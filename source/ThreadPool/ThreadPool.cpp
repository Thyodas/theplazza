/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** ThreadPool.cpp
*/

#include "ThreadPool.hpp"

namespace thread {
    void ThreadPool::stop()
    {
        {
            thread::UniqueLock lock(_queue_mutex);
            _should_terminate = true;
            _mutex_condition.notify_all();
        }
        for (auto &active_thread : _threads) {
            active_thread.join();
        }
        _threads.clear();
    }

    void ThreadPool::addJob(const std::function<void()> &job)
    {
        thread::UniqueLock lock(_queue_mutex);
        _jobs.push(job);
        _mutex_condition.notify_one();
    }

    ThreadPool::~ThreadPool() {
        stop();
    }

    void ThreadPool::start()
    {
        for (size_t i = 0; i < _nbThreads; ++i) {
            _threads.emplace_back(&ThreadPool::threadLoop, this);
        }
    }

    ThreadPool::ThreadPool(size_t nbThreads)
    : _nbThreads(nbThreads)
    {
    }

    ThreadPool::ThreadPool()
    : _nbThreads(std::thread::hardware_concurrency())
    {
    }

    void ThreadPool::threadLoop()
    {
        while (true) {
            std::function<void()> job;
            {
                thread::UniqueLock lock(_queue_mutex);
                _mutex_condition.wait(lock, [this] {
                    return !_jobs.empty() || _should_terminate;
                });
                if (_should_terminate) {
                    return;
                }
                job = _jobs.front();
                _jobs.pop();
            }
            _nbThreadWorking_mutex.lock();
            _nbThreadWorking += 1;
            _nbThreadWorking_mutex.unlock();
            job();
            _nbThreadWorking_mutex.lock();
            _nbThreadWorking -= 1;
            _nbThreadWorking_mutex.unlock();
        }
    }

    size_t ThreadPool::getNbJobs()
    {
        thread::UniqueLock lock(_queue_mutex);
        return _jobs.size();
    }

    size_t ThreadPool::getNbWorking()
    {
        thread::UniqueLock lock(_nbThreadWorking_mutex);
        return _nbThreadWorking;
    }
} // thread
