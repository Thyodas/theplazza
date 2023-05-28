/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** ThreadPool.hpp
*/

#pragma once

#include <vector>
#include <queue>
#include "../Thread/Thread.hpp"
#include "../Mutex/Mutex.hpp"
#include "IThreadPool.hpp"
#include "../ConditionVariable/ConditionVariable.hpp"
#include "../UniqueLock/UniqueLock.hpp"

namespace thread {

    class ThreadPool : public IThreadPool {
        public:
            explicit ThreadPool(size_t nbThreads);
            ThreadPool();
            ~ThreadPool() override;

            void start() override;
            void stop() override;
            void addJob(const std::function<void()> &job) override;
            size_t getNbJobs() const;

        private:
            void threadLoop();

            size_t _nbThreads;
            bool _should_terminate = false;
            thread::Mutex _queue_mutex;
            thread::ConditionVariable _mutex_condition{};
            std::vector<thread::Thread> _threads;
            std::queue<std::function<void()>> _jobs{};
    };
} // thread
