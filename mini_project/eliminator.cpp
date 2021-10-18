#include "eliminator.hpp"

#include <iomanip>
#include <iostream>

void InitInner(std::vector<std::vector<Cell_t>> &inner_state,
               const int grid[9][9]) {
  for (size_t i = 0; i < inner_state.size(); i++) {
    for (size_t j = 0; j < inner_state[0].size(); j++) {
      int value = grid[i][j];
      if (value) {
        AssignValue(i, j, value, inner_state);
      }
    }
  }
}

void AssignValue(const size_t &row, const size_t &col, const int &value,
                 std::vector<std::vector<Cell_t>> &inner_state) {
  inner_state[row][col].value = value;
  inner_state[row][col].possible.clear();
  EliminateInRow(value, row, inner_state);
  EliminateInCol(value, col, inner_state);
  EliminateInBox(value, row, col, inner_state);
}

bool IsSolved(const std::vector<std::vector<Cell_t>> &inner_state) {
  for (size_t i = 0; i < inner_state.size(); i++) {
    for (size_t j = 0; j < inner_state[0].size(); j++) {
      if (inner_state[i][j].possible.size() != 1) {
        return false;
      }
    }
  }
  return true;
}

void EliminateInRow(const int &value, const int &row,
                    std::vector<std::vector<Cell_t>> &inner_state) {
  for (size_t i = 0; i < inner_state.size(); i++) {
      std::vector<int> &possible_vec = inner_state[row][i].possible; // use reference of possible cuz I'm lazy
    if (possible_vec.size() != 0) {
      for (auto it = possible_vec.begin();
           it != possible_vec.end(); ++it) {
        if (value == *it) {
          possible_vec.erase(it);
          if (possible_vec.size() == 1) {
            AssignValue(row, i, possible_vec.at(0),
                        inner_state);
          }
          break;
        }
      }
    }
  }
}
void EliminateInCol(const int &value, const int &col,
                    std::vector<std::vector<Cell_t>> &inner_state) {
  for (size_t i = 0; i < inner_state.size(); i++) {
    std::vector<int> &possible_vec = inner_state[i][col].possible; // use reference cuz I'm lazy
    if (possible_vec.size() == 0) {
      continue;
    }
    for (auto it = possible_vec.begin();
         it != possible_vec.end(); ++it) {
      if (value == *it) {
        possible_vec.erase(it);
        if (possible_vec.size() == 1) {
          AssignValue(i, col, possible_vec.at(0), inner_state);
        }
        break;
      }
    }
  }
}
void EliminateInBox(const int &value, const int &row, const int &col,
                    std::vector<std::vector<Cell_t>> &inner_state) {
  int box_row = row - row % 3;
  int box_col = col - col % 3;
  for (size_t i = 0; i < 3; i++) {
    for (size_t j = 0; j < 3; j++) {
      std::vector<int> *temp_vec =
          &inner_state[box_row + i][box_col + j].possible;
      if (temp_vec->size() == 0) {
        continue;
      }
      for (auto it = temp_vec->begin(); it != temp_vec->end(); ++it) {
        if (value == *it) {
          temp_vec->erase(it);
          if (temp_vec->size() == 1) {
            AssignValue(box_row + i, box_col + j, temp_vec->at(0), inner_state);
          }
          break;
        }
      }
    }
  }
}