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
    /**
     * @brief Main class used to parse and store the command-line arguments
     */
    class Config {
        public:
            Config(int ac = 0, char **av = nullptr) : ac(ac), av(av)
            {
                if (ac == 4 && av != nullptr)
                    isFilled = true;
                extractArgs();
            };

            ~Config() = default;

            /**
             * @brief Get the Time Multiplier object
             *
             * @return float
             */
            float getTimeMultiplier() const
            {
                return timeMultiplier;
            }

            /**
             * @brief Get the Nb Cooks Per Kitchen object
             *
             * @return int
             */
            int getNbCooksPerKitchen() const
            {
                return nbCooksPerKitchen;
            }

            /**
             * @brief Get the Refill Ingredient object
             *
             * @return double
             */
            double getRefillIngredient() const
            {
                return refillIngredient;
            }

            friend std::ostream& operator<<(std::ostream& os, const utils::Config& cfg)
            {
                os << "timeMultiplier: " << cfg.getTimeMultiplier() <<
                            " nbCooksPerKitchen: " << cfg.getNbCooksPerKitchen() <<
                            " refillIngredient: " << cfg.getRefillIngredient();
                return os;
            }
        private:
            /**
             * @brief Extracts and store command-line arguments
             * It will throw an error if an argument is invalid or missing
             */
            void extractArgs()
            {
                if (!isFilled)
                    throw std::runtime_error("Config is not filled");
                try {
                    if ((timeMultiplier = std::stof(av[1])) < 0)
                        throw std::runtime_error("Invalid argument");
                    if ((nbCooksPerKitchen = std::stoi(av[2])) <= 0)
                        throw std::runtime_error("Invalid arguments");
                    if ((refillIngredient = std::stoi(av[3])) < 0)
                        throw std::runtime_error("Invalid argument");
                } catch (std::invalid_argument &e) {
                    throw std::runtime_error("Invalid argument");
                } catch (std::out_of_range &e) {
                    throw std::runtime_error("Invalid argument");
                }
            }
            int ac = 0;                     // number of arguments
            char **av = nullptr;            // arguments array
            bool isFilled = false;          // true if all arguments are filled
            float timeMultiplier = 0;       // 0.5 for /2, 1 for x1, 2 for x2, etc...
            int nbCooksPerKitchen = 0;   // number of cooks by kitchen
            double refillIngredient = 0;    // time between two refill in millisecond
    };

}
