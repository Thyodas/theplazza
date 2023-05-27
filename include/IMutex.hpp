/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** IMutex
*/

#pragma once

#include <mutex>

namespace thread {
    /**
     * @brief Main interface for encapsulating mutexes
     */
    class IMutex {
        public:
            //Virtual destructor
            virtual ~IMutex() = default;

            /**
             * @brief Used to lock the mutex
             */
            virtual void lock() = 0;
            /**
             * @brief If the mutex is available, returns true,
             * otherwise returns false
             * @return true 
             * @return false 
             */
            virtual bool tryLock() = 0;
            /**
             * @brief Used to unlokc the mutex
             */
            virtual void unlock() = 0;

            virtual operator std::mutex&() = 0;

    };
}
