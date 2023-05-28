/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Kitchen.cpp
*/

#include <algorithm>
#include "Kitchen.hpp"

namespace plazza {

    void Kitchen::startKitchen() {
        while (true) {
            checkRefillStock();
            if (_pizzaMq.isFilled())
                getCommands();
            //TODO: tryGetIngredients
            //TODO: takeIngredients
            sendStatus();
        }
    }

    bool Kitchen::tryGetIngredients(const pizzas::IPizza& pizza) const
    {
        return std::ranges::all_of(pizza.getIngredients(), [&](auto &ingredient) {
            return _stock.at(ingredient) > 0;
        });
    }

    void Kitchen::takeIngredients(const pizzas::IPizza& pizza)
    {
        for (auto &ingredient : pizza.getIngredients()) {
            _stock.at(ingredient) -= 1;
        }
    }

    void Kitchen::getCommands() {
        plazza::command_t command;
        command = _pizzaMq.receive();
        _commands.push(command);
    }

    void Kitchen::createNewKitchen(int id) {
        pid_t pid = fork();
        if (pid == 0) {
            _id = id;
            startKitchen();
        }
    }

    void Kitchen::checkRefillStock() {
        auto actualTime = std::chrono::system_clock::now();
        if (actualTime - _lastRefill > std::chrono::milliseconds(static_cast<long long>(_conf.getRefillIngredient()))) {
            refillStock();
            _lastRefill = actualTime;
        }
    }

    kitchenStatus_t Kitchen::getStatus() const {
        kitchenStatus_t status = {
                .id = _id,
                .isAlive = true,
                .doe = _stock.at(pizzas::Doe),
                .tomato = _stock.at(pizzas::Tomato),
                .gruyere = _stock.at(pizzas::Gruyere),
                .ham = _stock.at(pizzas::Ham),
                .mushrooms = _stock.at(pizzas::Mushrooms),
                .steak = _stock.at(pizzas::Steak),
                .eggplant = _stock.at(pizzas::Eggplant),
                .goatCheese = _stock.at(pizzas::GoatCheese),
                .chiefLove = _stock.at(pizzas::ChiefLove)
        };
        return status;
    }

    void Kitchen::sendStatus()
    {
        if (_statusMq.send(getStatus()))
            std::cerr << "Error while sending message" << std::endl;
    }

}
