/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.hpp
*/
#pragma once

#include <queue>
#include "Config.hpp"
#include "Shell.hpp"

class Core {
    public:
        Core(Config conf);
        ~Core() = default;
        void getArgs(Config conf);
        void mainLoop();
        void fillCommands();
        void sendCommands();
        void createKitchen();

    private:
        Config _conf;
        Shell shell;
        std::queue<command_t> _commands;
        float _multiplier;
        int _nbCooks;
        double _refillTime;
};
