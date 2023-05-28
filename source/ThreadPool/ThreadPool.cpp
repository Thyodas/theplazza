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
            job();
        }
    }

    size_t ThreadPool::getNbJobs() const
    {
        return _jobs.size();
    }
} // thread
