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
            Regina() = default;
    //        ~Regina();

        private:
            PizzaType _type = PizzaType::REGINA;
            std::vector<Ingredients_e> _ingredients = {
                Doe,
                Tomato,
                Gruyere,
                Ham,
                Mushrooms
            };
            double _bakeTime = 2;
    };
}
