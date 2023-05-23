/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.hpp
*/

#pragma once

#include <queue>
#include <vector>
#include <unistd.h>
#include <mqueue.h>
#include "Kitchen/Kitchen.hpp"
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
            void sendCommands(std::queue<command_t> commands);
            /**
             * @brief Adds a new kitchen
             */
            void createKitchen();
            /**
             * @brief Kills all the kitchens
             * @return true if all the kitchens have been killed, false otherwise
             */
            void killAllKitchens();
            /**
             * @brief Initializes the message queue
             */
            void initMQ();
            utils::Config _conf;
            Shell shell;
            std::vector<pid_t> _kitchens;
            mqd_t _mq;
    };
}

