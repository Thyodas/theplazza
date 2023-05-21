/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Americana.hpp
*/

#pragma once

#include "APizza.hpp"

class Americana final : public APizza {
	public:
		Americana() = default;
//		~Americana() final = default;

    private:
        PizzaType _type = PizzaType::Americana;
        std::vector<Ingredients_e> _ingredients = {
            Doe,
            Tomato,
            Gruyere,
            Steak
        };
        double _bakeTime = 2;
};
