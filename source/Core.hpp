/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.hpp
*/

#pragma once

#include <queue>

#include "Config/Config.hpp"
#include "Shell/Shell.hpp"

namespace plazza {

    class Core {
        public:
            Core(utils::Config conf);
            ~Core() = default;
            void getArgs(utils::Config conf);
            void mainLoop();
            void fillCommands();
            void sendCommands();
            void createKitchen();

        private:
            utils::Config _conf;
            Shell shell;
            std::queue<command_t> _commands;
            float _multiplier;
            int _nbCooks;
            double _refillTime;
    };
}

