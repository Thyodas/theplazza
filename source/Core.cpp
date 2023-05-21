/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace plazza {

    Core::Core(utils::Config conf) : _conf(conf), shell() {}

    void Core::mainLoop()
    {
        while (true) {
            shell.extractCommand();
            sendCommands(shell.getCommands());
        }
    }

    void Core::sendCommands(std::vector<command_t> commands)
    {

    }

    void Core::createKitchen()
    {

    }

}

