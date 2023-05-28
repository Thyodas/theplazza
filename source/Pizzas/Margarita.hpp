/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Margarita.hpp
*/

#pragma once

#include "APizza.hpp"
namespace pizzas {
    class Margarita final : public APizza {
        public:
            Margarita() = delete;
            explicit Margarita(const PizzaSize &size)
            : APizza(size) {
                _type = PizzaType::MARGARITA;
                _ingredients = {
                    Doe,
                    Tomato,
                    Gruyere
                };
                _bakeTime = 1;
            };
            ~Margarita() final = default;
    };
}
