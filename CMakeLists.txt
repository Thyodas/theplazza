cmake_minimum_required(VERSION 3.22)

project(plazza)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pthread")

include_directories(
        include/
        source/
        source/*
        lib/
)

set(INCLUDE
        include/IMessageQ.hpp
        include/IPizza.hpp
        include/APizza.hpp
        include/IMutex.hpp
        include/IThread.hpp
        include/Exception.hpp
        include/loguru.hpp
        )

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "source/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${INCLUDE})
