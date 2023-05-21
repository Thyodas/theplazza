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

class Kitchen {
    public:
        Kitchen(Config conf, int nbCooks = 0) : _pizzaFactory(), _conf(conf), _nbCooks(nbCooks) {
            initStock();
            startKitchen();
        };
        ~Kitchen() = default;

        void startKitchen();
        bool tryGetIngredients(const IPizza& pizza) const;
        void takeIngredients(const IPizza& pizza);
    private:
        PizzaFactory _pizzaFactory;
        Config _conf;
        std::map<Ingredients_e, int> _stock;
        std::vector<Cook> _cooks;
        int _nbCooks = 0;

        void initStock() {
            _stock[Doe] = 5;
            _stock[Tomato] = 5;
            _stock[Gruyere] = 5;
            _stock[Ham] = 5;
            _stock[Mushrooms] = 5;
            _stock[Steak] = 5;
            _stock[Eggplant] = 5;
            _stock[GoatCheese] = 5;
            _stock[ChiefLove] = 5;
        }
        void refillStock() {
            for (auto &ingredient : _stock)
                    ingredient.second += 1;
        }
};
