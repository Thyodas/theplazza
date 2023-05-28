/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Kitchen.cpp
*/

#include <algorithm>
#include <chrono>

#include "Kitchen.hpp"
#include "loguru.hpp"

namespace plazza {

    void Kitchen::startKitchen() {
        _threadPool.start();
        auto startTime = std::chrono::steady_clock::now();

        while (true) {
            checkRefillStock();
            if (_pizzaMq.isFilled()) {
                cookPizza();
                startTime = std::chrono::steady_clock::now();
            }
            auto currentTime = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsedSeconds = currentTime - startTime;
            if (elapsedSeconds.count() >= 5) {
                LOG_F(INFO, "Kitchen ID: %d wasn't used for 5 seconds.", _id);
                _isAlive = false;
                sendStatus();
                return;
            }
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

    void Kitchen::cookPizza() {
        short command;
        _pizzaMq >> command;
        auto pizza = _pizzaFactory.unpack(command);
        std::string pizza_name = pizza->getName();
        double bake_time = pizza->getBakeTime();
        double time_multiplier = this->_conf.getTimeMultiplier();
        takeIngredients(*pizza);
        _threadPool.addJob([pizza_name, time_multiplier, bake_time]() {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(static_cast<long long>(time_multiplier * bake_time * 1000))
            );
            std::cout << "\r\rPizza " << pizza_name << " is done!" << std::endl << "> " << std::flush;
            LOG_F(INFO, "Pizza %s is done!", pizza_name.c_str());
        });
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
        kitchenStatus_t status{};
        status.isAlive = _isAlive;
        status.id = _id;
        status.doe = _stock.at(pizzas::Doe);
        status.tomato = _stock.at(pizzas::Tomato);
        status.gruyere = _stock.at(pizzas::Gruyere);
        status.ham = _stock.at(pizzas::Ham);
        status.mushrooms = _stock.at(pizzas::Mushrooms);
        status.steak = _stock.at(pizzas::Steak);
        status.eggplant = _stock.at(pizzas::Eggplant);
        status.goatCheese = _stock.at(pizzas::GoatCheese);
        status.chiefLove = _stock.at(pizzas::ChiefLove);
        status.nbCommands = _nbCommands;
        return status;
    }

    void Kitchen::sendStatus()
    {
        _nbCommands = static_cast<int>(_threadPool.getNbJobs());
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
        _nbCommands = status.nbCommands;
    }

    void Kitchen::setPid(pid_t pid)
    {
        _pid = pid;
    }

    pid_t Kitchen::getPid() const
    {
        return _pid;
    }

    bool Kitchen::canTakePizza(const pizzas::IPizza &pizza) const
    {
        return tryGetIngredients(pizza) && _nbCommands < 2 * _conf.getNbCooksPerKitchen();
    }
}
