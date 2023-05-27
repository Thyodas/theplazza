/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Thread
*/

#pragma once

#include <thread>

#include "IThread.hpp"

namespace thread {

    class Thread final : public IThread {
        public:
            Thread() = delete;
            Thread(Thread &&other) noexcept;

            template<class Function, class... Args>
            explicit Thread(Function&& f, Args&&... args);

            Thread( const Thread& ) = delete;
            ~Thread() final = default;

            bool joinable() const noexcept final;
            std::thread::id getId() const noexcept final;
            void join() final;
            void detach() final;
    //        void swap(IThread& other) noexcept final;
        private:
            std::thread _thread;
    };

    template<class Function, class... Args>
    Thread::Thread(Function &&f, Args &&... args) {
        _thread = std::thread(f, args...);
    }

}


