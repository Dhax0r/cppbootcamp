#ifndef ELIMINATOR_HPP_
#define ELIMINATOR_HPP_
#include <vector>

typedef struct Cell {
    int value = -1;
    std::vector<int> possible = {1, 2, 3, 4, 5, 6, 7, 8, 9};

}Cell_t;

void InitInner(std::vector<std::vector<Cell_t>> &inner_state, const int grid[9][9]);
void EliminateInRow(const int &value, const int &row, std::vector<std::vector<Cell_t>> &inner_state);
void EliminateInCol(const int &value, const int &col, std::vector<std::vector<Cell_t>> &inner_state);
void EliminateInBox(const int &value, const int &row, const int &col, std::vector<std::vector<Cell_t>> &inner_state);
bool IsSolved(const std::vector<std::vector<Cell_t>> &inner_state);
void AssignValue(const size_t &row, const size_t &col, const int &value, std::vector<std::vector<Cell_t>> &inner_state);
#endif // ELIMINATOR_HPP_