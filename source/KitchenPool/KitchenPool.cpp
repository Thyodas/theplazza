/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** KitchenPool.cpp
*/

#include "KitchenPool.hpp"
#include "loguru.hpp"

namespace plazza {
    KitchenPool::KitchenPool(utils::Config config, const IPC::MessageQ<kitchenStatus_t> &statusMq)
    : _kitchens{}, _config(config), _statusMq(statusMq), _kitchenId(1)
    {
    }

    void KitchenPool::updateKitchenStatus(const kitchenStatus_t &status)
    {
        if (!status.isAlive) {
            destroyKitchen(status.id);
            return;
        }
        auto it = std::find_if(_kitchens.begin(), _kitchens.end(), [status](const auto& kitchen) {
            return kitchen->getId() == status.id;
        });
        if (it == _kitchens.end())
            return;
        (*it)->updateStatus(status);
    }

    void KitchenPool::sendPizza(const pizzas::IPizza &pizza)
    {
        std::vector<std::shared_ptr<Kitchen>> available;

        for (const auto &item: _kitchens) {
            if (item->canTakePizza(pizza)) {
                available.push_back(item);
            }
        }
        if (available.empty()) {
            createKitchen();
            sendPizza(pizza);
            return;
        }

        auto minCommandsKitchen = *std::min_element(
            available.begin(), available.end(),
            [](const std::shared_ptr<Kitchen>& kitchen1, const std::shared_ptr<Kitchen>& kitchen2) {
                return kitchen1->getStatus().nbCommands < kitchen2->getStatus().nbCommands;
            }
        );

        minCommandsKitchen->sendPizza(pizza);
    }

    void KitchenPool::createKitchen()
    {
        _kitchens.emplace_back(std::make_shared<Kitchen>(_config, _statusMq, _kitchenId++));
        int pid = fork();
        _kitchens.back()->setPid(pid);
        if (pid == 0) {
            _kitchens.back()->startKitchen();
            exit(0);
        }
        LOG_F(INFO, "New kitchen created. PID: %d, ID: %d.", pid, _kitchens.back()->getId());
    }

    void KitchenPool::destroyKitchen(int id)
    {
        std::erase_if(_kitchens, [id](auto& kitchen) {
            if (kitchen->getId() != id)
                return false;
            LOG_F(INFO, "Destroyed kitchen in pool. PID: %d, ID: %d.",
                kitchen->getPid(), kitchen->getId());
            return true;
        });
    }

    KitchenPool::~KitchenPool()
    {
        for (auto &i: _kitchens) {
            kill(i->getPid(), SIGKILL);
            LOG_F(INFO, "Killed kitchen in pool. PID: %d, ID: %d.", i->getPid(), i->getId());
        }
    }

    std::string KitchenPool::getAllStatus() const
    {
        std::string str;
        if (_kitchens.empty()) {
            str = "No kitchen are currently in the pool.\n";
            return str;
        }
        for (const auto &item: _kitchens) {
            kitchenStatus_t s = item->getStatus();
            str += "Status for kitchen PID: " + std::to_string(item->getPid())
                   + " ID: " + std::to_string(item->getId()) + "\n"
                   + "\t Job number: " + std::to_string(s.nbCommands) + "\n"
                   + "\t Doe: " + std::to_string(s.doe) + "\n"
                   + "\t Tomato: " + std::to_string(s.tomato) + "\n"
                   + "\t Ham: " + std::to_string(s.ham) + "\n"
                   + "\t Gruyere: " + std::to_string(s.gruyere) + "\n"
                   + "\t Mushrooms: " + std::to_string(s.mushrooms) + "\n"
                   + "\t Steak: " + std::to_string(s.steak) + "\n"
                   + "\t Eggplant: " + std::to_string(s.eggplant) + "\n"
                   + "\t Goat Cheese: " + std::to_string(s.goatCheese) + "\n"
                   + "\t Chief Love: " + std::to_string(s.chiefLove) + "\n";
            str += "\n";
        }
        return str;
    }
} // plazza
