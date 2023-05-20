/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Thread
*/
#pragma once

#include <thread>
#include "interfaces/IThread.hpp"

class Thread final : public IThread{
    public:
        Thread() = delete;
        Thread(Thread &&other) noexcept;
        template<class Function, class... Args>
        Thread(Function&& f, Args&&... args);
        Thread( const Thread& ) = delete;
        ~Thread() final = default;

        bool joinable() const noexcept final;
        std::thread::id getId() const noexcept final;
        void join() final;
        void detach() final;
//        void swap(IThread& other) noexcept final;
    protected:
    private:
        std::thread _thread;
        std::thread::id _id;
};

