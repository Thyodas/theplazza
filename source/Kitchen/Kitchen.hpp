/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Kitchen.hpp
*/

#pragma once

#include <map>
#include <ranges>
#include <csignal>

#include "IPizza.hpp"
#include "../PizzaFactory/PizzaFactory.hpp"
#include "../Config/Config.hpp"
#include "../Cook/Cook.hpp"
#include "../MessageQ/MessageQ.hpp"

typedef struct {
    int id;
    bool isAlive;
    int doe;
    int tomato;
    int gruyere;
    int ham;
    int mushrooms;
    int steak;
    int eggplant;
    int goatCheese;
    int chiefLove;
} kitchenStatus_t;

namespace plazza {
    /**
     * @brief Main class used for the kitchens
     */
    class Kitchen {
        public:
            Kitchen(utils::Config conf, const IPC::MessageQ<command_t> &pizzaMq, const IPC::MessageQ<kitchenStatus_t> &statusMq, int nbCooks = 0) : _pizzaFactory(),
            _conf(conf), _nbCooks(nbCooks), _pizzaMq(pizzaMq), _statusMq(statusMq) {
                initStock();
            };
            ~Kitchen() {
                for (auto &pid : _pids) {
                    kill(pid, SIGKILL);
                }
            };

            /**
             * @brief Starts the kitchen
             */
            void startKitchen();

            /**
             * @brief Returns true if the ingredient of the pizza are
             * available in the stock
             * @param pizza The pizza to check
             * @return true if the ingredients are available, false otherwise
             */
            bool tryGetIngredients(const pizzas::IPizza& pizza) const;

            /**
             * @brief Remove the ingredient of the pizza from the stock
             * @param pizza The pizza to take the ingredients from
             */
            void takeIngredients(const pizzas::IPizza& pizza);

            //TODO: documentation
            void getCommands();

            //TODO: documentation
            void createNewKitchen(int id);

            //TODO: documentation
            kitchenStatus_t getStatus() const;

            //TODO: documentation
            void sendStatus();

        private:
            pizzas::PizzaFactory _pizzaFactory;
            utils::Config _conf;
            std::map<pizzas::Ingredients_e, int> _stock;
            std::vector<Cook> _cooks;
            int _nbCooks = 0;
            IPC::MessageQ<command_t> _pizzaMq;
            IPC::MessageQ<kitchenStatus_t> _statusMq;
            int _id = 0;
            std::queue<command_t> _commands;
            std::chrono::time_point<std::chrono::system_clock> _lastRefill;
            std::vector<pid_t> _pids;


            //TODO: documentation
            void checkRefillStock();

            /**
             * @brief Initalizes all the stocks inside the kitchens
             */
            void initStock() {
                _stock[pizzas::Doe] = 5;
                _stock[pizzas::Tomato] = 5;
                _stock[pizzas::Gruyere] = 5;
                _stock[pizzas::Ham] = 5;
                _stock[pizzas::Mushrooms] = 5;
                _stock[pizzas::Steak] = 5;
                _stock[pizzas::Eggplant] = 5;
                _stock[pizzas::GoatCheese] = 5;
                _stock[pizzas::ChiefLove] = 5;
            }
            /**
             * @brief Function called every N seconds to refill the ingredients
             * stocks
             */
            void refillStock() {
                for (auto &ingredient : _stock)
                        ingredient.second += 1;
            }
    };
}
