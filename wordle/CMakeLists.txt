cmake_minimum_required(VERSION 3.24)
project(wordle C)

set(CMAKE_C_STANDARD 11)

include_directories(incl)

add_executable(wordle
        incl/wordle.h
        src/parsing/parsing_dictionnary.c
        src/main.c)
