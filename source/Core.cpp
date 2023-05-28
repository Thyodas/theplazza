/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace plazza {

    Core::Core(utils::Config conf)
    : _conf(conf), shell(), _statusMq(0), _kitchenPool(conf, _statusMq) {}

    void Core::mainLoop()
    {
        while (true) {
            if (shell.extractCommand() == -1)
                return;
            sendCommands(shell.getCommands());
        }
    }

    void Core::sendCommands(std::queue<command_t> commands)
    {
        while (!commands.empty()) {
            command_t command = commands.front();
            for (size_t i = 0; i < command.quantity; ++i) {
                auto pizza = _pizzaFactory.createPizza(command.type, command.size);
                fetchAndUpdateStatus();
                _kitchenPool.sendPizza(*pizza);
            }
            commands.pop();
        }
    }

    void Core::fetchAndUpdateStatus()
    {
        kitchenStatus_t status;
        std::cout << "fetch" << std::endl;
        while (_statusMq.isFilled()) {
            _statusMq >> status;
            std::cout << "\r\rNew status from id: " << status.id << std::endl << "> " << std::flush;
            _kitchenPool.updateKitchenStatus(status);
        }
    }
}
