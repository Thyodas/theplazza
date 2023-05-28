/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Americana.hpp
*/

#pragma once

#include "APizza.hpp"

namespace pizzas {
    class Americana final : public APizza {
        public:
            Americana() = delete;
            explicit Americana(const PizzaSize &size) : APizza(size) {
                _type = PizzaType::AMERICANA;
                _ingredients = {
                    Doe,
                    Tomato,
                    Gruyere,
                    Steak
                };
                _bakeTime = 2;
            };
            ~Americana() final = default;
    };
}
