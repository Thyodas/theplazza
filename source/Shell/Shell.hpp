/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Shell
*/

#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "IPizza.hpp"

typedef struct command_s {
    command_s(PizzaType type, PizzaSize size, size_t quantity) : type(type), size(size), quantity(quantity) {};
    command_s() : type(UNDEFINED), size(S), quantity(0) {}
    void print() const { std::cout << "Type: " << type << " Size: " << size << " Quantity: " << quantity << std::endl; }
    PizzaType type;
    PizzaSize size;
    size_t quantity;
} command_t;

class Shell {
    public:
        Shell();
        ~Shell() = default;

        void getInput();
        void extractCommand();
        const std::vector<command_t> &getCommands() const;
    private:
        std::vector<std::string> _input;
        std::vector<command_t> _commands;
        std::map<std::string, PizzaType> _typeMap = {
                {"regina",    REGINA},
                {"margarita", MARGARITA},
                {"americana", AMERICANA},
                {"fantasia",  FANTASIA}
        };
        std::map<std::string, PizzaSize> _sizeMap = {
            {"S", S},
            {"M", M},
            {"L", L},
            {"XL", XL},
            {"XXL", XXL}
        };
};
