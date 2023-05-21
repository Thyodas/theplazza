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
            /**
             * @brief Main loop of the program
             */
            void mainLoop();

        private:
            /**
             * @brief Function called when all the commands have been parsed
             *
             * @param commands
             */
            void sendCommands(std::vector<command_t> commands);
            /**
             * @brief Adds a new kitchen
             */
            void createKitchen();
            utils::Config _conf;
            Shell shell;
    };
}

