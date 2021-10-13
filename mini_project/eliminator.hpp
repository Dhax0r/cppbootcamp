#ifndef ELIMINATOR_HPP_
#define ELIMINATOR_HPP_
#include <vector>

typedef struct Cell {
    std::vector<int> possible = {1, 2, 3, 4, 5, 6, 7, 8, 9};

}Cell_t;

void InitInner(Cell_t inner_state[9][9],const int grid[9][9]);
void EliminateInRow(const int &value, const int &row, Cell_t inner_state[9][9]);
void EliminateInCol(const int &value, const int &col, Cell_t inner_state[9][9]);
void EliminateInBox(const int &value, const int &row, const int &col, Cell_t inner_state[9][9]);
bool IsSolved(const Cell_t inner_state[9][9]);

#endif // ELIMINATOR_HPP_