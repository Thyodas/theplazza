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
    class Kitchen {
        public:
            Kitchen(utils::Config conf, int nbCooks = 0) : _pizzaFactory(), _conf(conf), _nbCooks(nbCooks) {
                initStock();
                startKitchen();
            };
            ~Kitchen() = default;

            void startKitchen();
            bool tryGetIngredients(const pizzas::IPizza& pizza) const;
            void takeIngredients(const pizzas::IPizza& pizza);
        private:
            pizzas::PizzaFactory _pizzaFactory;
            utils::Config _conf;
            std::map<pizzas::Ingredients_e, int> _stock;
            std::vector<Cook> _cooks;
            int _nbCooks = 0;

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
            void refillStock() {
                for (auto &ingredient : _stock)
                        ingredient.second += 1;
            }
    };

}
