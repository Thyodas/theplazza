/*
** EPITECH PROJECT, 2023
** plazza
** File description:
** Core.cpp
*/

#include <csignal>
#include "Core.hpp"

namespace plazza {

    Core::Core(utils::Config conf) : _conf(conf), shell() {
        try {
            initMQ();
        } catch (std::runtime_error &e) {
            std::cerr << e.what() << std::endl;
            exit(84);
        }
    }

    void Core::mainLoop()
    {
        while (true) {
            shell.extractCommand();
            sendCommands(shell.getCommands());
        }
    }

    void Core::sendCommands(std::queue<command_t> commands)
    {
        while (!commands.empty()) {
            command_t command = commands.front();
            commands.pop();
            if (mq_send(_mq, reinterpret_cast<char *>(&command), sizeof(command_t), 0) == -1)
                std::cerr << "Error while sending message" << std::endl;
        }
    }

    void Core::createKitchen()
    {
        pid_t pid = fork();
        if (pid == 0) {
            Kitchen kitchen(_conf, _conf.getNbCooksPerKitchen());
        } else {
            _kitchens.push_back(pid);
        }
    }

    void Core::killAllKitchens()
    {
        for (auto i: _kitchens) {
            if (kill(i, SIGKILL) == -1)
                std::cerr << "Error while killing kitchen, pid: " << i << std::endl;
        }
    }

    void Core::initMQ()
    {
        mq_attr mqAttr {
            .mq_flags = 0,
            .mq_maxmsg = 10,
            .mq_msgsize = sizeof(command_t),
            .mq_curmsgs = 0,
            .__pad = {0}
        };
        _mq = mq_open("/plazza", O_CREAT | O_RDWR, 0644, &mqAttr);
        if (_mq == -1)
            throw std::runtime_error("Error while creating message queue");
    }

}

