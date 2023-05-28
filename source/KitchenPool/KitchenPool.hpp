/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** KitchenPool.hpp
*/

#pragma once

#include <cstddef>
#include <vector>
#include "../Kitchen/Kitchen.hpp"

namespace plazza {

    class KitchenPool {
        public:
            KitchenPool(utils::Config config, const IPC::MessageQ<kitchenStatus_t> &statusMq);

            ~KitchenPool();

            void updateKitchenStatus(const kitchenStatus_t &status);
            void sendPizza(const pizzas::IPizza &pizza);

            std::string getAllStatus() const;

        private:
            /**
             * @brief Adds a new kitchen
             */
            void createKitchen();

            void destroyKitchen(int id);

            std::vector<std::shared_ptr<Kitchen>> _kitchens;
            utils::Config _config;
            IPC::MessageQ<kitchenStatus_t> _statusMq;
            int _kitchenId = 1;
    };
} // plazza
