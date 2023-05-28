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
                getPizza();
            //TODO: tryGetIngredients
            //TODO: takeIngredients

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
        sendStatus();
    }

    void Kitchen::getPizza() {
        short command;
//        command = _pizzaMq.receive();
        _pizzaMq >> command;
        auto pizza = _pizzaFactory.unpack(command);
        std::cout << "\r\rReceived command: " << pizza->getBakeTime() << std::endl << "> " << std::flush;
        //_commands.push(command);
    }

    void Kitchen::createNewKitchen(int id) {
        pid_t pid = fork();
        if (pid == 0) {
            _id = id;
            startKitchen();
        } else
            _pids.emplace_back(pid);
    }

    void Kitchen::checkRefillStock() {
        auto actualTime = std::chrono::system_clock::now();
        if (actualTime - _lastRefill > std::chrono::milliseconds(static_cast<long long>(_conf.getRefillIngredient()))) {
            refillStock();
            _lastRefill = actualTime;
            sendStatus();
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
        if ((_statusMq << getStatus()) == -1)
            std::cerr << "Error while sending message" << std::endl;
    }

    void Kitchen::sendPizza(const pizzas::IPizza &pizza) const
    {
        if ((_pizzaMq << pizza.pack()) == -1)
            std::cerr << "Error while sending message" << std::endl;
    }

    int Kitchen::getId() const
    {
        return _id;
    }

    void Kitchen::updateStatus(const kitchenStatus_t &status)
    {
        _stock.at(pizzas::Doe) = status.doe;
        _stock.at(pizzas::Tomato) = status.tomato;
        _stock.at(pizzas::Gruyere) = status.gruyere;
        _stock.at(pizzas::Ham) = status.ham;
        _stock.at(pizzas::Mushrooms) = status.mushrooms;
        _stock.at(pizzas::Steak) = status.steak;
        _stock.at(pizzas::Eggplant) = status.eggplant;
        _stock.at(pizzas::GoatCheese) = status.goatCheese;
        _stock.at(pizzas::ChiefLove) = status.chiefLove;
    }

    void Kitchen::setPid(pid_t pid)
    {
        _pid = pid;
    }

    pid_t Kitchen::getPid() const
    {
        return _pid;
    }
}
