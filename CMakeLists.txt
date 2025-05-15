cmake_minimum_required(VERSION 3.26)
project(BP C)

set(CMAKE_C_STANDARD 17)
add_compile_options(-Wall -Wextra -Wpedantic)
add_executable(BP main/main.c
        sortingFunctions/sortingFunctions.c
        sortingFunctions/sortingFunctions.h
        printingWritingFunctions/printingWritingFunctions.c
        printingWritingFunctions/printingWritingFunctions.h
        structDefinition/structDefinition.h
        loadFunctions/loadFunctions.c
        loadFunctions/loadFunctions.h)


