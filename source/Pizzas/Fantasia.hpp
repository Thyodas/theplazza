/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Fantasia.hpp
*/

#pragma once

#include "APizza.hpp"

namespace pizzas {
    class Fantasia final : public APizza {
        public:
            Fantasia() = default;
            Fantasia(const PizzaSize &size) : APizza(size) {};
            ~Fantasia() final = default;

        private:
            PizzaType _type = PizzaType::FANTASIA;
            std::vector<Ingredients_e> _ingredients = {
                Doe,
                Tomato,
                Eggplant,
                GoatCheese,
                ChiefLove
            };
            double _bakeTime = 4;
    };
}
