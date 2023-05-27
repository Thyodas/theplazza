/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** PizzaFactory.cpp
*/

#include "PizzaFactory.hpp"

#include "../include/IPizza.hpp"
#include "../Pizzas/Americana.hpp"
#include "../Pizzas/Fantasia.hpp"
#include "../Pizzas/Margarita.hpp"
#include "../Pizzas/Regina.hpp"

namespace pizzas {

    template<typename T>
    void PizzaFactory::registerComponent(const PizzaType &type)
    {
        constructorMap[type] = [](const PizzaSize size) {
            return std::make_unique<T>(size);
        };
    }

    std::unique_ptr<IPizza> PizzaFactory::createPizza(const PizzaType type, const PizzaSize size) const
    {
        if (constructorMap.find(type) == constructorMap.end())
            throw exception::UnknownTypeException("Unknown type");
        return constructorMap.at(type)(size);
    }

    PizzaFactory::PizzaFactory()
    {
        registerComponent<Americana>(AMERICANA);
        registerComponent<Fantasia>(FANTASIA);
        registerComponent<Margarita>(MARGARITA);
        registerComponent<Regina>(REGINA);
    }

}

