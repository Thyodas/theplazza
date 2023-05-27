/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** IThreadPool.hpp
*/

#pragma once

#include <functional>

namespace thread {

    class IThreadPool {
        public:
            virtual ~IThreadPool() = default;

            virtual void start() = 0;
            virtual void stop() = 0;

            virtual void addJob(const std::function<void()>& job) = 0;

    };
} // thread
