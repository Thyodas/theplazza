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
            Margarita() = default;
            Margarita(const PizzaSize &size) : APizza(size) {};
            ~Margarita() final = default;

        private:
            PizzaType _type = PizzaType::MARGARITA;
            std::vector<Ingredients_e> _ingredients = {
                Doe,
                Tomato,
                Gruyere
            };
            double _bakeTime = 1;
    };
}
