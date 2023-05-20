/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Mutex
*/
#pragma once

#include <mutex>
#include "interfaces/IMutex.hpp"

class Mutex : public IMutex {
	public:
		Mutex();
		~Mutex() {};

        void lock();
        bool trylock();
        void unlock();
	protected:
	private:
        std::mutex _mutex;
};
