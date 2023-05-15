/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** main
*/

#include <iostream>
#include "Shell.hpp"

int main()
{
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
