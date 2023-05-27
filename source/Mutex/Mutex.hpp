/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Mutex
*/

#pragma once

#include <mutex>
#include "IMutex.hpp"

namespace thread {
    class Mutex final : public IMutex {
        public:
            Mutex() = default;
            ~Mutex() final = default;

            void lock() final;
            bool tryLock() final;
            void unlock() final;

            explicit operator std::mutex&() final;
        private:
            std::mutex _mutex;
    };
}

