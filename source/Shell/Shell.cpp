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

Shell::Shell() = default;

void Shell::getInput() {
    _input.clear();
    std::string input;
    std::cout << "> " << std::flush; //TODO: remove prompt maybe?
    std::getline(std::cin, input);
    if (input.find(';') != std::string::npos) {
        std::stringstream ss(input);
        while (std::getline(ss, input, ';')) {
            _input.emplace_back(input);
        }
    } else
        _input.emplace_back(input);
}

void Shell::extractCommand() {
    _commands.clear();
    std::regex regex(R"(([a-zA-Z]+)\s+(S|M|L|XL|XXL)\s+x(\d{1,}))");
    for (const auto & i : _input) {
        command_t command;
        std::smatch match;
        if (std::regex_search(i, match, regex)) {
            command.type = _typeMap[match[1]];
            command.size = _sizeMap[match[2]];
            command.quantity = std::stoi(match[3]);
            _commands.emplace_back(command);
        } else {
            std::cerr << "Invalid command: " << i << std::endl;
        }
    }
}

const std::vector<command_t> &Shell::getCommands() const {
    return _commands;
}
