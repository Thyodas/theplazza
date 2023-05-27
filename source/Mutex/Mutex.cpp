/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Mutex.cpp
*/

#include "Mutex.hpp"
namespace thread {

    void Mutex::lock() {
        _mutex.lock();
    }

    bool Mutex::tryLock() {
        return _mutex.try_lock();
    }

    void Mutex::unlock() {
        _mutex.unlock();
    }

    Mutex::operator std::mutex&()
    {
        return _mutex;
    }
}
