#include "valid.hpp"

bool IsValid(const size_t &row, const size_t &col, const int &value,
             const Grid_t &inner_state) {
  return IsValidRow(row, value, inner_state) &&
         IsValidCol(col, value, inner_state) &&
         IsValidBox(row, col, value, inner_state);
}
bool IsValidRow(const size_t &row, const int &value,
                const Grid_t &inner_state) {
  for (size_t i = 0; i < inner_state[0].size(); i++) {
    if (inner_state[row][i].value == value) {
      return false;
    }
  }
  return true;
}

bool IsValidCol(const size_t &col, const int &value,
                const Grid_t &inner_state) {
  for (size_t i = 0; i < inner_state.size(); i++) {
    if (inner_state[i][col].value == value) {
      return false;
    }
  }
  return true;
}

bool IsValidBox(const size_t &row, const size_t &col, const int &value,
                const Grid_t &inner_state) {
  size_t box_row = row - row % 3;
  size_t box_col = col - col % 3;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      if (inner_state[box_row + i][box_col + j].value == value) {
        return false;
      }
    }
  }
  return true;
}