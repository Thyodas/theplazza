/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Fantasia.hpp
*/
#pragma once

#include "pizza/APizza.hpp"

class Fantasia final : public APizza {
    public:
        Fantasia() = default;
//        ~Fantasia();

    private:
        PizzaType _type = PizzaType::Fantasia;
        std::vector<Ingredients_e> _ingredients = {
            Doe,
            Tomato,
            Eggplant,
            GoatCheese,
            ChiefLove
        };
        double _bakeTime = 4;
};
