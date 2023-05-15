/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** main
*/

#include <iostream>
#include "Shell.hpp"
#include "Config.hpp"

int main(int ac, char **av)
{
    Config conf(ac, av);
    try {
        if (!conf.errorHandling())
            return 84;
        conf.extractArgs();
        conf.print();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    Shell shell;
    while (true) {
        shell.getInput();
        shell.extractCommand();
        for (const auto &i: shell.getCommands()) {
            i.print();
        }
    }
    return 0;
}
