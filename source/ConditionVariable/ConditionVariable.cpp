/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** ConditionalVariable.cpp
*/

#include "ConditionVariable.hpp"

namespace thread {

    void ConditionVariable::wait(thread::UniqueLock& lock) {
        cv.wait(static_cast<std::unique_lock<std::mutex>&>(lock));
    }

    void ConditionVariable::notify_one() {
        cv.notify_one();
    }

    void ConditionVariable::notify_all() {
        cv.notify_all();
    }

} // thread