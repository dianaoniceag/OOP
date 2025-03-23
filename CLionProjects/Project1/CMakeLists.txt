cmake_minimum_required(VERSION 3.22)
project(Project1 C)

add_executable(Project1 main.c
        Cheltuiala.c
        Cheltuiala.h
        Controller.c
        Controller.h
        UI.c
        UI.h)


set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_C_FLAGS "--coverage -O0 -g ${CMAKE_CXX_FLAGS}")
