#include "unique.hpp"
#include "eliminator.hpp"

// Go through grid and check if any peers are unique
void UniquePeer(Grid_t &inner_state) {
for (size_t i = 0; i < 81; i++) {
    if (inner_state[i/9][i%9].value != -1){
      continue;
    }
    for (auto p : inner_state[i/9][i%9].possible) {
      if (UniqueInRow(p, i/9, i%9, inner_state)) {
        AssignValue(i/9, i%9, p, inner_state);
      }
      if (UniqueInCol(p, i/9, i%9, inner_state)) {
        AssignValue(i/9, i%9, p, inner_state);
      }
      if (UniqueInBox(p, i/9, i%9, inner_state)) {
        AssignValue(i/9, i%9, p, inner_state);
      }
    }
  }
}
bool UniqueInRow(const int &value, const size_t &row, const size_t &col, Grid_t inner_state) {
  for (size_t i = 0; i < 9; i++) {
    if (i == col) {
      continue;
    }
    for (auto p : inner_state[row][i].possible) {
      if (p == value || inner_state[row][i].value == value) {
        return false;
      }
    }
  }
  return true;
}
bool UniqueInCol(const int &value, const size_t &row, const size_t &col, const Grid_t &inner_state) {
  for (size_t i = 0; i < 9; i++) {
    if (i == row) {
      continue;
    }
    for (auto p : inner_state[i][col].possible) {
      if (p == value) {
        return false;
      }
    }
  }
  return true;
}
bool UniqueInBox(const int &value, const size_t &row, const size_t &col, const Grid_t &inner_state) {
  size_t box_row = row - row % 3;
  size_t box_col = col - col % 3;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if ((box_row + i) == row && (box_col + j) == col) {
        continue;
      }
      for (auto p : inner_state[box_row + i][box_col + j].possible) {
        if (p == value) {
          return false;
        }
      }
    }
  }
return true;
}