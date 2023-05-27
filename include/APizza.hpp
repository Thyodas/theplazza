/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** APizza.hpp
*/

#pragma once

#include "IPizza.hpp"

namespace pizzas {

    /**
     * @brief Main abstract class implementing the basic interface
     * methods.
     */
    class APizza : public IPizza {
        public:
            APizza() = default;
            APizza(const PizzaSize &size) : _size(size) {};
            ~APizza() override = default;

        std::vector<Ingredients_e> getIngredients() const override
        {
            return _ingredients;
        }

        double getBakeTime() const override
        {
            return _bakeTime;
        }

        short pack() const final
        {
            return short(_type << 8 | _size);
        }

        protected:
            PizzaType _type = PizzaType::REGINA;
            PizzaSize _size = PizzaSize::S;
            std::vector<Ingredients_e> _ingredients = {};
            double _bakeTime = 0;
    };
}

