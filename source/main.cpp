/*
** EPITECH PROJECT, 2023
** B-CCP-400-STG-4-1-theplazza-remi.mergen
** File description:
** main
*/

#include <iostream>

#include "Config/Config.hpp"
#include "Core.hpp"
#include "ThreadPool/ThreadPool.hpp"
#include "loguru.hpp"

int main(int ac, char **av)
{
    try {
        utils::Config conf(ac, av);
        std::cout << conf << std::endl;
        thread::ThreadPool pool(10);
        for (int i = 0; i < 12; ++i) {
            pool.addJob([i]() {
                int test = 1 + i;
                fprintf(stderr, "test %d\n", test);
            });
        }
        pool.start();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }

    return 0;
}
