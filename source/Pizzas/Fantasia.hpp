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
            Fantasia() = delete;
            Fantasia(const PizzaSize &size) : APizza(size) {
                _type = PizzaType::FANTASIA;
                _ingredients = {
                    Doe,
                    Tomato,
                    Eggplant,
                    GoatCheese,
                    ChiefLove
                };
                _bakeTime = 4;
            };
            ~Fantasia() final = default;
    };
}
