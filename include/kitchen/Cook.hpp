/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Cook.hpp
*/
#pragma once

#include "Thread.hpp"

class Cook {
	public:
		Cook();
		~Cook() = default;

	private:
        Thread _thread;
};
