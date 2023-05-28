/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Shell
*/

#pragma once

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

#include "IPizza.hpp"

namespace plazza {

    /**
     * @brief Struct defining a command
     * It contains the pizza type, size and quantity
     */
    typedef struct command_s {
        command_s(pizzas::PizzaType type, pizzas::PizzaSize size, size_t quantity)
            : type(type), size(size), quantity(quantity) {};
        command_s() : type(pizzas::STATUS), size(pizzas::S), quantity(0) {}
        void print() const { std::cout << "Type: " << type << " Size: " << size << " Quantity: " << quantity << std::endl; }
        pizzas::PizzaType type;
        pizzas::PizzaSize size;
        size_t quantity;
    } command_t;

    const std::map<std::string, pizzas::PizzaType> _typeMap = {
            {"regina",    pizzas::REGINA},
            {"margarita", pizzas::MARGARITA},
            {"americana", pizzas::AMERICANA},
            {"fantasia",  pizzas::FANTASIA}
    };
    const std::map<std::string, pizzas::PizzaSize> _sizeMap = {
        {"S", pizzas::S},
        {"M", pizzas::M},
        {"L", pizzas::L},
        {"XL", pizzas::XL},
        {"XXL", pizzas::XXL}
    };

    /**
     * @brief Main class that represents the reception
     */
    class Shell {
        public:
            Shell();
            ~Shell() = default;

            /**
             * @brief This function will fill the commands vector based on
             * the input parsed before
             * This function should be called after getInput
             */
            void extractCommand();
            /**
             * @brief Get the Commands object
             *
             * @return const std::vector<command_t>&
             */
            std::queue<command_t> getCommands() const;
        private:
            /**
             * @brief Parse the stdin and split the text based on ; separators
             * and then returns it
             * This function should be called first
             *
             * @return std::vector<std::string>&
             */
            std::vector<std::string> getInput();

            std::queue<command_t> _commands;
    };
}
