#ifndef _GRID_HPP_
#define _GRID_HPP_
#include <vector>
#include <array>

typedef struct Cell {
  int value = -1;
  std::vector<int> possible = {1, 2, 3, 4, 5, 6, 7, 8, 9};

} Cell_t;
//typedef std::vector<std::vector<Cell_t>> Grid_t;
typedef std::array<std::array<Cell_t,9>,9> Grid_t;

#endif // _GRID_HPP_