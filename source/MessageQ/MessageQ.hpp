/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** MessageQ.hpp
*/

#pragma once

#include <ostream>
#include "IMessageQ.hpp"

namespace IPC {

    template <typename T>
    class MessageQ final : public IMessageQ<T> {
        public:
            MessageQ(int projId) {
                key_t key = ftok(".", projId);
                _mqId = msgget(key, IPC_CREAT | 0666);
                if (_mqId == -1) {
                    throw std::runtime_error("Error while creating message queue");
                }
            };
            ~MessageQ() final {
                //msgctl(_mqId, IPC_RMID, nullptr);
            };
            bool isFilled() final {
                struct msqid_ds queueInfo{};
                if (msgctl(_mqId, IPC_STAT, &queueInfo) == -1) {
                    throw std::runtime_error("Error retrieving information about the message queue.");
                }
                return queueInfo.msg_qnum != 0;
            }

            friend int operator<<(const MessageQ<T> &q, const T &command) {
                struct Message<T> msg = {1, command};
                if (msgsnd(q._mqId, &msg, sizeof(T), 0) == -1) {
                    throw std::runtime_error("Error while sending message");
                }
                return 0;
            };

            friend void operator>>(const MessageQ<T> &q, T &command) {
                struct Message<T> msg{};
                if (msgrcv(q._mqId, &msg, sizeof(T), 1, 0) == -1) {
                    throw std::runtime_error("Error while receiving message");
                }
                command = msg.command;
            };

            int send(const T &command) final {
                struct Message<T> msg = {1, command};
                if (msgsnd(_mqId, &msg, sizeof(T), 0) == -1) {
                    throw std::runtime_error("Error while sending message");
                }
                return 0;
            };
            T receive() final {
                struct Message<T> msg{};
                if (msgrcv(_mqId, &msg, sizeof(T), 1, 0) == -1) {
                    throw std::runtime_error("Error while receiving message");
                }
                return msg.command;
            };
        private:
            int _mqId = -1;
    };
}
