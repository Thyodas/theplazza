/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Shell.cpp
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>

#include "Shell.hpp"

namespace plazza {

    Shell::Shell() = default;

    std::vector<std::string> Shell::getInput()
    {
        std::vector<std::string> inputs;
        std::string input;
        std::cout << "> " << std::flush; //TODO: remove prompt maybe?
        std::getline(std::cin, input);
        if (std::cin.eof() || std::cin.fail())
            return inputs;
        if (input.find(';') != std::string::npos) {
            std::stringstream ss(input);
            while (!std::cin.eof() && std::getline(ss, input, ';'))
                inputs.emplace_back(input);
        } else
            inputs.emplace_back(input);
        return inputs;
    }

    int Shell::extractCommand()
    {
        std::queue<command_t> empty;
        std::swap(empty, _commands);
        std::vector<std::string> inputs = getInput();
        if (inputs.empty())
            return -1;
        std::regex regex(R"(([a-zA-Z]+)\s+(S|M|L|XL|XXL)\s+x(\d{1,}))");
        try {
            for (const auto & i : inputs) {
                if (i.empty())
                    continue;
                command_t command;
                if (i == "status") {
                    command.type = pizzas::STATUS;
                    command.size = pizzas::S;
                    command.quantity = 0;
                    _commands.push(command);
                    continue;
                }
                std::smatch smash;
                if (std::regex_search(i, smash, regex)) {
                    command.type = _typeMap.at(smash[1]);
                    command.size = _sizeMap.at(smash[2]);
                    command.quantity = std::stoi(smash[3]);
                    _commands.push(command);
                } else
                    std::cerr << "Invalid command: " << i << std::endl;
            }
        } catch (std::invalid_argument &e) {
            std::cerr << "Invalid argument" << std::endl;
        } catch (std::out_of_range &e) {
            std::cerr << "Invalid argument" << std::endl;
        }
        return 0;
    }

    std::queue<command_t> Shell::getCommands() const
    {
        return _commands;
    }

}

