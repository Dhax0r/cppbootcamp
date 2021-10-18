#include "print_sudoku.hpp"
#include <iostream>
#include <iomanip>

void Print(const int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        std::cout << "|";
        for (int j = 0; j < 9; j++) {
            std::cout <<grid[i][j] << "|";
        }
        std::cout << std::endl;
    }
}


void Print(const std::vector<std::vector<Cell_t>> &inner_state) {
  
    for (size_t i = 0; i < 9; i++){
        for (size_t j = 0; j < 9; j++) {
          std::cout << std::setw(9);
             /* for (auto v : inner_state[i][j].possible) {
                std::cout << v;
            } */ 
            std::cout << inner_state[i][j].value;
            std::cout <<  ",";
        }
        std::cout << std::endl;
    }
}