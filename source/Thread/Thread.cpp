/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Thread.cpp
*/

#include "Thread.hpp"

namespace thread {

    Thread::Thread(Thread &&other) noexcept {
        _thread = std::move(other._thread);
    }

    std::thread::id Thread::getId() const noexcept{
        return _thread.get_id();
    }

    bool Thread::joinable() const noexcept{
        return _thread.joinable();
    }

    void Thread::join() {
        _thread.join();
    }

    void Thread::detach() {
        _thread.detach();
    }

    //void Thread::swap(IThread &other) noexcept {
    //    _thread.swap(other._thread);
    //}
}

