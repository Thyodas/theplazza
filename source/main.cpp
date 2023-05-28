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
#include "loguru.hpp"

int main(int ac, char **av)
{
    try {
        loguru::g_stderr_verbosity = 1;
        loguru::init(ac, av);
        loguru::add_file("plazza.log", loguru::Truncate, loguru::Verbosity_MAX);
        utils::Config conf(ac, av);
        LOG_F(INFO, "Starting plazza with %.2f time multiplier, %d workers "
                    "and %.2f milliseconds to replace ingredients.",
            conf.getTimeMultiplier(), conf.getNbCooksPerKitchen(), conf.getRefillIngredient());
        plazza::Core core(conf);
        core.mainLoop();
        loguru::shutdown();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return 84;
    }
    return 0;
}
