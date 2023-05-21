/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Cook.hpp
*/

#pragma once

#include <iostream>
#include <memory>

#include "../Thread/Thread.hpp"
#include "IPizza.hpp"

namespace plazza {
    /**
     * @brief Main class used for the cooks
     */
    class Cook {
        public:
            Cook(const std::shared_ptr<pizzas::IPizza>& pizza, int bakeTime = 1)
                : _pizza(pizza),
                _thread(&Cook::cookWrapper, this, bakeTime)
            {

            }
            ~Cook() = default;

            /**
             * @brief Function called to simulation the cooking time
             * @param time
             * @param multiplier
             */
            void cook(int time = 1, int multiplier = 1) {
                //TODO: log
                std::this_thread::sleep_for(std::chrono::seconds (time * multiplier));
            }
            /**
             * @brief Function called when the pizza is done cooking
             *
             */
            void stop() {
                //TODO: log
                _thread.detach();
            }
        private:
            /**
             * @brief Wrapper passed as constructor argument to the pizza
             * thread
             * @param bakeTime
             */
            void cookWrapper(int bakeTime)
            {
                cook(bakeTime);
                stop();
            }

            std::shared_ptr<pizzas::IPizza> _pizza;
            thread::Thread _thread;
    };

}
