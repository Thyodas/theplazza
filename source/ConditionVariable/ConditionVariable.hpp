/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** ConditionalVariable.hpp
*/

#pragma once

#include <condition_variable>

#include "../UniqueLock/UniqueLock.hpp"
#include "../Mutex/Mutex.hpp"

namespace thread {

    class ConditionVariable {
        public:
            ConditionVariable() = default;
            ~ConditionVariable() = default;

            void wait(thread::UniqueLock &lock);

            template <class Predicate>
            void wait(thread::UniqueLock& lock, Predicate pred) {
                cv.wait(static_cast<std::unique_lock<std::mutex>&>(lock), pred);
            }

            void notify_one();

            void notify_all();
        private:
            std::condition_variable cv;
    };

} // thread
