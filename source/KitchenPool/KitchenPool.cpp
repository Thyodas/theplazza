/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** KitchenPool.cpp
*/

#include "KitchenPool.hpp"

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
        auto it = std::find_if(_kitchens.begin(), _kitchens.end(), [status](const Kitchen& kitchen) {
            return kitchen.getId() == status.id;
        });
        if (it == _kitchens.end())
            return;
        it->updateStatus(status);
    }

    void KitchenPool::sendPizza(const pizzas::IPizza &pizza)
    {
        for (const auto &item: _kitchens) {
            if (item.tryGetIngredients(pizza)) {
                item.sendPizza(pizza);
                return;
            }
        }
        createKitchen();
        sendPizza(pizza);
    }

    void KitchenPool::createKitchen()
    {
        _kitchens.emplace_back(_config, _statusMq, _kitchenId++);
        int pid = fork();
        _kitchens.back().setPid(pid);
        if (pid == 0) {
            _kitchens.back().startKitchen();
            exit(0);
        }
    }

    void KitchenPool::destroyKitchen(int id)
    {
        std::erase_if(_kitchens, [id](Kitchen& kitchen) {
            return kitchen.getId() == id;
        });
    }

    KitchenPool::~KitchenPool()
    {
        for (auto &i: _kitchens) {
            kill(i.getPid(), SIGKILL);
        }
    }
} // plazza
