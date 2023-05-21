/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.cpp
*/

#include "Core.hpp"

Core::Core(Config conf) : _conf(conf), shell() {}

void Core::getArgs(Config conf)
{
    _multiplier = conf.getTimeMultiplier();
    _nbCooks = conf.getNbCooksPerKitchen();
    _refillTime = conf.getRefillIngredient();
}

void Core::mainLoop()
{
    while (true) {
        fillCommands();
        sendCommands();
    }
}

void Core::fillCommands()
{
    shell.getInput();
    shell.extractCommand();
    std::vector<command_t> commands = shell.getCommands();
    for (auto &command : commands)
        _commands.push(command);
}

void Core::sendCommands()
{

}

void Core::createKitchen()
{

}
