/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** Exception.cpp
*/

#pragma once

#include <stdexcept>

namespace exception {
    /**
     * @brief Abstract class defining all our exceptions
     *
     */
    class AException : public std::exception {
        public:
            [[nodiscard]] const char *what() const noexcept override
            {
                return _message.c_str();
            }
        protected:
            explicit AException(const std::string &message) : _message(message) {};
            std::string _message;
    };

    /**
     * @brief Exception class used when the mentionned pizza type
     * is undefined
     */
    class UnknownTypeException : public AException {
        public:
            explicit UnknownTypeException(const std::string &message) : AException(message) {};
    };
}