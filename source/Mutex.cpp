/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Mutex.cpp
*/

#include "../include/Mutex.hpp"

Mutex::Mutex()
{
    //_mutex;
}

void Mutex::lock() {
    _mutex.lock();
}

bool Mutex::trylock() {
    _mutex.try_lock();
    return true;
}

void Mutex::unlock() {
    _mutex.unlock();
}
