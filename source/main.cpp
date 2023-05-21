/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** main
*/

#include <iostream>

#include "Config/Config.hpp"
#include "Core.hpp"

int main(int ac, char **av)
{
    try {
        utils::Config conf(ac, av);
        std::cout << conf << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    //plazza::Core core(conf);
    return 0;
}
