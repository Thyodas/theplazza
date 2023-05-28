/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Regina.hpp
*/

#pragma once

#include "APizza.hpp"
namespace pizzas {
    class Regina final : public APizza {
        public:
            Regina() = delete;
            explicit Regina(const PizzaSize &size) : APizza(size) {
                _type = PizzaType::REGINA;
                _ingredients = {
                    Doe,
                    Tomato,
                    Gruyere,
                    Ham,
                    Mushrooms
                };
                _bakeTime = 2;
            };
            ~Regina() final = default;
    };
}
