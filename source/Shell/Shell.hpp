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

namespace plazza {
    typedef struct command_s {
        command_s(pizzas::PizzaType type, pizzas::PizzaSize size, size_t quantity)
            : type(type), size(size), quantity(quantity) {};
        command_s() : type(pizzas::UNDEFINED), size(pizzas::S), quantity(0) {}
        void print() const { std::cout << "Type: " << type << " Size: " << size << " Quantity: " << quantity << std::endl; }
        pizzas::PizzaType type;
        pizzas::PizzaSize size;
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
            std::map<std::string, pizzas::PizzaType> _typeMap = {
                    {"regina",    pizzas::REGINA},
                    {"margarita", pizzas::MARGARITA},
                    {"americana", pizzas::AMERICANA},
                    {"fantasia",  pizzas::FANTASIA}
            };
            std::map<std::string, pizzas::PizzaSize> _sizeMap = {
                {"S", pizzas::S},
                {"M", pizzas::M},
                {"L", pizzas::L},
                {"XL", pizzas::XL},
                {"XXL", pizzas::XXL}
            };
    };
}
