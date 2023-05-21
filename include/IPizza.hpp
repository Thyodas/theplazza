/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** IPizza.hpp
*/

#pragma once

#include <vector>

enum Ingredients_e {
    Doe,
    Tomato,
    Gruyere,
    Ham,
    Mushrooms,
    Steak,
    Eggplant,
    GoatCheese,
    ChiefLove,
};

enum PizzaType {
    REGINA = 1,
    MARGARITA = 2,
    AMERICANA = 4,
    FANTASIA = 8,
    UNDEFINED = 16
};

enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

class IPizza {
    public:
        virtual ~IPizza() = default;

        virtual std::vector<Ingredients_e> getIngredients() const = 0;
        virtual double getBakeTime() const = 0;
        virtual short pack() const = 0;
};
