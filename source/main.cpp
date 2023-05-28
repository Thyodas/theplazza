/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** main
*/

#include <iostream>
#include <cstring>

#include "Config/Config.hpp"
#include "Core.hpp"
#include "IMessageQ.hpp"

int main(int ac, char **av)
{
    try {
        utils::Config conf(ac, av);
        plazza::Core core(conf);
        core.mainLoop();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return 84;
    }
    return 0;
}
