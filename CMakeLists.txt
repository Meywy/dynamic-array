cmake_minimum_required(VERSION 3.16)
project(dyn_pole_funkce LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(program
    main.c
    array.c
    menu.c
)

target_compile_options(program PRIVATE -Wall -Wextra)
