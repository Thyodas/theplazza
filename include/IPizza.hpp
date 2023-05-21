/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** IPizza.hpp
*/

#pragma once

#include <vector>

namespace pizzas {

    //Enum containing all the ingredients
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

    //Enum containing all the pizza types
    enum PizzaType {
        REGINA = 1,
        MARGARITA = 2,
        AMERICANA = 4,
        FANTASIA = 8,
        UNDEFINED = 16
    };

    //Enum containing all the pizza sizes
    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    /**
     * @brief Main pizza interface
     */
    class IPizza {
        public:
            //Virtual destructor
            virtual ~IPizza() = default;

            /**
             * @brief This function should return the ingredients
             * composing the pizza
             */
            virtual std::vector<Ingredients_e> getIngredients() const = 0;
            /**
             * @brief Get the Bake Time object
             *
             * @return double
             */
            virtual double getBakeTime() const = 0;
            /**
             * @brief This function should return a short containing
             * the information both the type and size of the pizzas.
             * It will be used inside the IPC.
             *
             * @return short
             */
            virtual short pack() const = 0;
    };

}

