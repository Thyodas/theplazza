/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.hpp
*/
#pragma once
#include "Config.hpp"

class Core {
    public:
        Core();
        ~Core() = default;
        void getArgs(Config conf);
    protected:
    private:
        Config conf;
};
