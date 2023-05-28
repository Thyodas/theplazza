/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace plazza {

    Core::Core(utils::Config conf) : _conf(conf), shell(), _pizzaMq('A'), _statusMq('B'),
                        _kitchen(_conf, _pizzaMq, _statusMq, _conf.getNbCooksPerKitchen()) {}

    void Core::mainLoop()
    {
        createKitchen();
        while (true) {
            shell.extractCommand();
            sendCommands(shell.getCommands());
        }
    }

    void Core::sendCommands(std::queue<command_t> commands)
    {
        while (!commands.empty()) {
            command_t command = commands.front();
            commands.pop();
            if (_pizzaMq.send(command) == -1)
                std::cerr << "Error while sending message" << std::endl;
        }
    }

    void Core::createKitchen()
    {
        _kitchen.createNewKitchen(_lastKitchenId);
        ++_lastKitchenId;
    }
//    void Core::killAllKitchens()
//    {
//        for (auto i: _kitchens) {
//            if (kill(i, SIGKILL) == -1)
//                std::cerr << "Error while killing kitchen, pid: " << i << std::endl;
//        }
//    }

}

