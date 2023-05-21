/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** IThread
*/

#pragma once

#include <thread>

namespace thread {
    /**
     * @brief Main interface used to encapsulate threads
     */
    class IThread {
        public:
            //Virtual destructor
            virtual ~IThread() = default;
            /**
             * @brief Returns true if the thread is joinable,
             * false otherwise
             * @return true
             * @return false
             */
            virtual bool joinable() const noexcept = 0;
            /**
             * @brief Get the Id object
             *
             * @return std::thread::id
             */
            virtual std::thread::id getId() const noexcept = 0;
            /**
             * @brief Joins the thread
             */
            virtual void join() = 0;
            /**
             * @brief Detaches from the thread
             */
            virtual void detach() = 0;
    //        virtual void swap(IThread& other) noexcept = 0;
    };
}
