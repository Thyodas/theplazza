/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Config.hpp
*/

#pragma once

#include <cstddef>
#include <string>
#include <stdexcept>
#include <iostream>

namespace utils {

    class Config {
        public:
            Config(int ac = 0, char **av = nullptr) : ac(ac), av(av) {
                if (ac == 4 && av != nullptr)
                    isFilled = true;
            };
            ~Config() = default;

            void checkFilled() {
                if (!isFilled)
                    throw std::runtime_error("Config is not filled");
            }
            bool errorHandling() {
                checkFilled();
                try {
                    if (ac != 4)
                        return false;
                    if (std::stof(av[1]) <= 0)
                        return false;
                    if (std::stoi(av[2]) <= 0)
                        return false;
                    if (std::stoi(av[3]) <= 0)
                        return false;
                    return true;
                } catch (std::invalid_argument &e) {
                    std::cerr << "Invalid argument" << std::endl;
                    return false;
                } catch (std::out_of_range &e) {
                    std::cerr << "One argument or more is out of range" << std::endl;
                    return false;
                }
            }
            void extractArgs() {
                checkFilled();
                timeMultiplier = std::stof(av[1]);
                nbCooksPerKitchen = std::stoi(av[2]);
                refillIngredient = std::stoi(av[3]);
            }
            void print() {
                checkFilled();
                std::cout << "timeMultiplier: " << timeMultiplier <<
                " nbCooksPerKitchen: " << nbCooksPerKitchen <<
                " refillIngredient: " << refillIngredient << std::endl;
            }
            float getTimeMultiplier() const {
                return timeMultiplier;
            }
            int getNbCooksPerKitchen() const {
                return nbCooksPerKitchen;
            }
            double getRefillIngredient() const {
                return refillIngredient;
            }
        private:
            int ac = 0;                     // number of arguments
            char **av = nullptr;            // arguments array
            bool isFilled = false;          // true if all arguments are filled
            float timeMultiplier = 0;       // 0.5 for /2, 1 for x1, 2 for x2, etc...
            int nbCooksPerKitchen = 0;   // number of cooks by kitchen
            double refillIngredient = 0;    // number of ingredients to refill in millisecond
    };

}
