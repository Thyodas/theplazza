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
            fetchAndUpdateStatus();
            if (command.type == pizzas::STATUS) {
                std::cout << _kitchenPool.getAllStatus() << std::endl;
                commands.pop();
                continue;
            }
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
        while (_statusMq.isFilled()) {
            _statusMq >> status;
            _kitchenPool.updateKitchenStatus(status);
        }
    }
}
