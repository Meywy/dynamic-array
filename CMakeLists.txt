add_executable(program
    src/main.c
    src/array.c
    src/menu.c
)

target_include_directories(program PRIVATE include)
target_compile_options(program PRIVATE -Wall -Wextra)
