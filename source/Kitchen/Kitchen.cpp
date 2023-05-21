/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Kitchen.cpp
*/

#include <algorithm>
#include <ranges>
#include "Kitchen.hpp"

void Kitchen::startKitchen() {

}

bool Kitchen::tryGetIngredients(const IPizza& pizza) const
{
    return std::ranges::all_of(pizza.getIngredients(), [&](auto &ingredient) {
        return _stock.at(ingredient) > 0;
    });
}

void Kitchen::takeIngredients(const IPizza& pizza)
{
    for (auto &ingredient : pizza.getIngredients()) {
        _stock.at(ingredient) -= 1;
    }
}
