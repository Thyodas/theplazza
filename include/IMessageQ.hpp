/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** IMessageQ.hpp
*/
#pragma once

#include <mqueue.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>

#include "../source/Shell/Shell.hpp"

namespace IPC {
    template <typename T>
    struct Message {
        long mtype{};
        T command;
    };

    template <typename T>
    class IMessageQ {
    public:
        virtual ~IMessageQ() = default;
        virtual bool isFilled() = 0;
        virtual int send(const T &command) = 0;
        virtual T receive() = 0;
    };
}
