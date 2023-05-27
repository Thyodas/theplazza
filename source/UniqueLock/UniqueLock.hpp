/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** UniqueLock.hpp
*/

#pragma once

#include "../Mutex/Mutex.hpp"

#include <mutex>

namespace thread {

    class UniqueLock {
        public:
            explicit UniqueLock(thread::Mutex& mtx);
            ~UniqueLock() = default;

            UniqueLock(const UniqueLock&) = delete;
            UniqueLock& operator=(const UniqueLock&) = delete;

            void lock();
            void unlock();

            explicit operator std::unique_lock<std::mutex>&();

        private:
            std::unique_lock<std::mutex> ulock;
    };

} // thread
