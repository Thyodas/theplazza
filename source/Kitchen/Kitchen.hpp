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
            Kitchen(const Kitchen &kitchen)
            : _pizzaFactory(), _conf(kitchen._conf),
            _pizzaMq(kitchen._pizzaMq), _statusMq(kitchen._statusMq) {}
            Kitchen(utils::Config conf, IPC::MessageQ<kitchenStatus_t> &statusMq, int id)
            : _pizzaFactory(), _conf(conf), _pizzaMq(id), _statusMq(statusMq), _id(id) {
                initStock();
            };
            ~Kitchen() = default;

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


            void sendPizza(const pizzas::IPizza& pizza) const;

            //TODO: documentation
            void createNewKitchen(int id);

            //TODO: documentation
            kitchenStatus_t getStatus() const;

            void updateStatus(const kitchenStatus_t &status);

            int getId() const;
            void setPid(pid_t pid);
            pid_t getPid() const;


        private:
            pizzas::PizzaFactory _pizzaFactory;
            utils::Config _conf;
            std::map<pizzas::Ingredients_e, int> _stock;
            //std::vector<Cook> _cooks;
            IPC::MessageQ<short> _pizzaMq;
            IPC::MessageQ<kitchenStatus_t> _statusMq;
            int _id = 0;
            pid_t _pid;
            std::queue<command_t> _commands;
            std::chrono::time_point<std::chrono::system_clock> _lastRefill;
            std::vector<pid_t> _pids;


            /**
             * @brief Remove the ingredient of the pizza from the stock
             * @param pizza The pizza to take the ingredients from
             */
            void takeIngredients(const pizzas::IPizza& pizza);

            void sendStatus();

            //TODO: documentation
            void getPizza();

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
