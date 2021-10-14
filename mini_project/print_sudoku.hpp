#ifndef PRINT_SUDOKU_HPP_
#define PRINT_SUDOKU_HPP_
#include "eliminator.hpp"

void Print(const int grid[9][9]);
void Print(const std::vector<std::vector<Cell_t>> &inner_state);
#endif // PRINT_SUDOKU_HPP_