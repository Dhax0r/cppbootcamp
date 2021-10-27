cmake_minimum_required(VERSION 3.16.3)
project(sudoku)

add_executable(${PROJECT_NAME}
main.cpp
)

add_library(print STATIC
print_sudoku.cpp)

add_library(eliminator 
eliminator.cpp)

target_link_libraries(${PROJECT_NAME}
print
eliminator)