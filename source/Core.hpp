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
#include "MessageQ/MessageQ.hpp"
#include "KitchenPool/KitchenPool.hpp"

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

            void fetchAndUpdateStatus();

            void waitAndUpdateStatus();

            utils::Config _conf;
            Shell shell;
            IPC::MessageQ<kitchenStatus_t> _statusMq;
            KitchenPool _kitchenPool;
            int _lastKitchenId = 0;
            pizzas::PizzaFactory _pizzaFactory;
    };
}
