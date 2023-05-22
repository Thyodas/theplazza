/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Kitchen.hpp
*/

#pragma once

#include <map>
#include <ranges>

#include "IPizza.hpp"
#include "../PizzaFactory/PizzaFactory.hpp"
#include "../Config/Config.hpp"
#include "../Cook/Cook.hpp"

namespace plazza {
    /**
     * @brief Main class used for the kitchens
     */
    class Kitchen {
        public:
            Kitchen(utils::Config conf, int nbCooks = 0) : _pizzaFactory(), _conf(conf), _nbCooks(nbCooks) {
                initStock();
                startKitchen();
            };
            ~Kitchen() = default;

            /**
             * @brief Starts the kitchen
             */
            void startKitchen();

            /**
             * @brief Returns true if the ingredient of the pizza are
             * available in the stock
             * @return true if the ingredients are available, false otherwise
             */
            bool tryGetIngredients(const pizzas::IPizza& pizza) const;

            /**
             * @brief Remove the ingredient of the pizza from the stock
             * @param pizza
             */
            void takeIngredients(const pizzas::IPizza& pizza);
        private:
            pizzas::PizzaFactory _pizzaFactory;
            utils::Config _conf;
            std::map<pizzas::Ingredients_e, int> _stock;
            std::vector<Cook> _cooks;
            int _nbCooks = 0;

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
