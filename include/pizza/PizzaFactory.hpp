/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** PizzaFactory.hpp
*/
#pragma once

#include <map>
#include "IPizza.hpp"

using FuncCreatePizza = IPizza (*)(const PizzaSize &);

class PizzaFactory {
public:

    static IPizza createAmericana(const PizzaSize &pizzaSize);
    static IPizza createFantasia(const PizzaSize &pizzaSize);
    static IPizza createMargarita(const PizzaSize &pizzaSize);
    static IPizza createRegina(const PizzaSize &pizzaSize);

    PizzaFactory();
    ~PizzaFactory();

    IPizza unpack(short pizzaType) const {
        return _pizzaMap.at(PizzaType(pizzaType >> 8))(PizzaSize(pizzaType & 0xFF));
    }
    IPizza createPizza(PizzaType pizzaType, PizzaSize pizzaSize) const {
        return _pizzaMap.at(pizzaType)(pizzaSize);
    }

private:
    std::map<PizzaType, FuncCreatePizza> _pizzaMap = {
        {Americana, createAmericana},
        {Fantasia, createFantasia},
        {Margarita, createMargarita},
        {Regina, createRegina}
    };
};
