/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** UniqueLock.cpp
*/

#include "UniqueLock.hpp"

namespace thread {

    UniqueLock::UniqueLock(thread::Mutex& mtx)
    : ulock(static_cast<std::mutex &>(mtx)) {}

    void UniqueLock::lock() {
        ulock.lock();
    }

    void UniqueLock::unlock() {
        ulock.unlock();
    }

    UniqueLock::operator std::unique_lock<std::mutex>&()
    {
        return ulock;
    }
} // thread