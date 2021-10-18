#include "print_sudoku.hpp"

#include <iomanip>
#include <iostream>

void Print(const int grid[9][9]) {
  for (int i = 0; i < 9; i++) {
    std::cout << "|";
    for (int j = 0; j < 9; j++) {
      std::cout << grid[i][j] << "|";
    }
    std::cout << std::endl;
  }
}

void Print(const std::vector<std::vector<Cell_t>> &inner_state) {
  for (size_t i = 0; i < 9; i++) {
    for (size_t j = 0; j < 9; j++) {
      std::cout << std::setw(9);
      if (inner_state[i][j].value == -1) {
        for (auto v : inner_state[i][j].possible) {
          std::cout << v;
        }
      } else {
        std::cout << inner_state[i][j].value;
      }
      std::cout << ",";
    }
    std::cout << std::endl;
  }
}