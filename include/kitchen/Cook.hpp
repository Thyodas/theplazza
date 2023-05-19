/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Cook.hpp
*/
#pragma once

#include <iostream>
#include <memory>
#include "Thread.hpp"
#include "IPizza.hpp"

class Cook {
    public:
        Cook(const std::shared_ptr<IPizza> &pizza, int bakeTime = 1) : _pizza(pizza), _thread([=, this] {
            this->cook(bakeTime);
            this->stop();
        }) {};
        ~Cook() = default;

        void cook(int time = 1, int multiplier = 1) {
            //TODO: log
            std::this_thread::sleep_for(std::chrono::seconds (time * multiplier));
        }
        void stop() {
            //TODO: log
            _thread.detach();
        }
    private:
        std::shared_ptr<IPizza> _pizza;
        Thread _thread;
};
