/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Margarita.hpp
*/

#pragma once

#include "APizza.hpp"

class Margarita final : public APizza {
    public:
        Margarita() = default;
//        ~Margarita();

    private:
        PizzaType _type = PizzaType::Margarita;
        std::vector<Ingredients_e> _ingredients = {
            Doe,
            Tomato,
            Gruyere
        };
        double _bakeTime = 1;
};
