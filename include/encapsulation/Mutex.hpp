/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Mutex
*/
#pragma once

#include <mutex>
#include "IMutex.hpp"

class Mutex final : public IMutex {
    public:
        Mutex();
        ~Mutex() final = default;

        void lock() final;
        bool trylock() final;
        void unlock() final;
    private:
        std::mutex _mutex;
};
