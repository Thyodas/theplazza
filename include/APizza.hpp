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

        std::string getName() final
        {
            std::string str;
            switch (_type) {
                case REGINA:
                    str += "Regina";
                    break;
                case MARGARITA:
                    str += "Margarita";
                    break;
                case AMERICANA:
                    str += "Americana";
                    break;
                case FANTASIA:
                    str += "Fantasia";
                    break;
                default:
                    str += "Unknown Pizza";
                    break;
            }
            str += " ";
            switch (_size) {
                case S:
                    str += "S";
                    break;
                case M:
                    str += "M";
                    break;
                case L:
                    str += "L";
                    break;
                case XL:
                    str += "XL";
                    break;
                case XXL:
                    str += "XXL";
                    break;
                default:
                    str += "Unknown Size";
                    break;
            }
            return str;
        }

        PizzaType getType() final
        {
            return _type;
        }


        protected:
            PizzaType _type = PizzaType::REGINA;
            PizzaSize _size = PizzaSize::S;
            std::vector<Ingredients_e> _ingredients = {};
            double _bakeTime = 0;
    };
}

