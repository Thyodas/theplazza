/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** PizzaFactory.hpp
*/

#pragma once

#include <unordered_map>
#include <memory>
#include <functional>

#include "IPizza.hpp"
#include "Exception.hpp"

namespace pizzas {
    class PizzaFactory {
        public:
            PizzaFactory();
            ~PizzaFactory() = default;

            std::unique_ptr<IPizza> unpack(short pack) const
            {
                return createPizza(PizzaType(pack >> 8), PizzaSize(pack & 0xFF));
            };
            std::unique_ptr<IPizza> createPizza(const PizzaType type, const PizzaSize size) const;
        private:
            template<typename T>
            void registerComponent(const PizzaType &type);
            std::unordered_map<PizzaType, std::function<std::unique_ptr<IPizza>(const PizzaSize size)>> constructorMap;
    };
}

