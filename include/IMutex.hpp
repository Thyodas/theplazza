/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** IMutex
*/

#pragma once

class IMutex {
    public:
        virtual ~IMutex() = default;

        virtual void lock() = 0;
        virtual bool trylock() = 0;
        virtual void unlock() = 0;
};
