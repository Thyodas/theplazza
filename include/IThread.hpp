/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** IThread
*/

#pragma once

#include <thread>

namespace thread {
    class IThread {
        public:
            virtual ~IThread() = default;

            virtual bool joinable() const noexcept = 0;
            virtual std::thread::id getId() const noexcept = 0;
            virtual void join() = 0;
            virtual void detach() = 0;
    //        virtual void swap(IThread& other) noexcept = 0;
    };
}
