#include "eliminator.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>

#include "print_sudoku.hpp"
#include "unique.hpp"
#include "valid.hpp"

void Solve(Grid_t &inner_state, const int grid[9][9]) {
  for (size_t i = 0; i < inner_state.size(); i++) {
    for (size_t j = 0; j < inner_state[0].size(); j++) {
      int value = grid[i][j];
      if (value) {
        AssignValue(i, j, value, inner_state);
      }
    }
  }
  /* if (!IsSolved(inner_state)) {
    BruteForce(inner_state);
  } */
}

void Solve(const std::string &s, Grid_t &inner_state) {
  for (size_t i = 0; i < s.size(); i++) {
    size_t r = i / 9;
    size_t c = i % 9;
    if (s[i] != '.') {
      int value = s[i] - '0';
      AssignValue(r, c, value, inner_state);
    }
  }
}

bool BruteForce(Grid_t &inner_state) {
  if (IsSolved(inner_state)) {
    return true;
  }
  Grid_t inner_copy = inner_state;
  size_t min_row, min_col;
  FindMinPeers(min_row, min_col, inner_copy);
  for (int c : inner_copy[min_row][min_col].possible) {
    if (!AssignValue(min_row, min_col, c, inner_copy)) {
      inner_copy = inner_state;
      continue;
    }
    if (BruteForce(inner_copy)) {
      inner_state = inner_copy;
      return true;
    } else {
      inner_copy = inner_state;  // if value not correct reset inner_copy
    }
  }
  return false;
}

bool AssignValue(const size_t &row, const size_t &col, const int &value,
                 Grid_t &inner_state) {
  /* if (!IsValid(row, col, value, inner_state)) {
    return false;
  } */

  inner_state[row][col].value = value;
  inner_state[row][col].possible.clear();
  /* EliminateInRow(value, row, inner_state);
  EliminateInCol(value, col, inner_state);
  EliminateInBox(value, row, col, inner_state); */
  Eliminate(row, col, value, inner_state);
  UniquePeer(inner_state);

  return true;
}

bool IsSolved(const Grid_t &inner_state) {
  for (size_t i = 0; i < inner_state.size(); i++) {
    for (size_t j = 0; j < inner_state[0].size(); j++) {
      if (inner_state[i][j].value == -1) {
        return false;
      }
    }
  }
  return true;
}
void Eliminate(const size_t &row, const size_t &col, const int &value,
               Grid_t &inner_state) {
  Print(inner_state);
  for (size_t i = 0; i < inner_state.size(); i++) {
    std::vector<int> &row_possible = inner_state[row][i].possible;
    row_possible.erase(std::remove_if(row_possible.begin(), row_possible.end(),
                                      [&value](int &x) { return value == x; }),
                       row_possible.end());
    if (row_possible.size() == 1) {
      AssignValue(row, i, row_possible.at(0), inner_state);
    }
    std::vector<int> &col_possible = inner_state[i][col].possible;
    col_possible.erase(std::remove_if(col_possible.begin(), col_possible.end(),
                                      [&value](int &x) { return value == x; }),
                       col_possible.end());
    if (col_possible.size() == 1) {
      AssignValue(i, col, col_possible.at(0), inner_state);
    }
    size_t box_row = row - row % 3;
    size_t box_col = col - col % 3;
    std::vector<int> &box_possible =
        inner_state[box_row + i / 3][box_col + i % 3].possible;
    box_possible.erase(std::remove_if(box_possible.begin(), box_possible.end(),
                                      [&value](int &x) { return value == x; }),
                       box_possible.end());
    if (box_possible.size() == 1) {
      AssignValue(box_row + i/3, box_col + i%3, box_possible.at(0), inner_state);
    }    
    /* for (auto it = row_possible.begin(); it != row_possible.end(); ++it) {
      if (*it == value) {
        row_possible.erase(it);

        if (row_possible.size() == 1) {
          AssignValue(row, i, row_possible.at(0), inner_state);
        }
        break;
      }
    } */
    /* std::vector<int> &col_possible = inner_state[i][col].possible;
    for (auto it = col_possible.begin(); it != col_possible.end(); ++it) {
      if (*it == value) {
        col_possible.erase(it);

        if (col_possible.size() == 1) {
          AssignValue(col, i, col_possible.at(0), inner_state);
        }
        break;
      }
    }
    size_t box_row = row - row % 3;
    size_t box_col = col - col % 3;
    std::vector<int> &box_possible =
        inner_state[box_row + i / 3][box_col + i % 3].possible;
    for (auto it = box_possible.begin(); it != box_possible.end(); ++it) {
      if (*it == value) {
        box_possible.erase(it);

        if (box_possible.size() == 1) {
          AssignValue(box_row + i / 3, box_col + i % 3, box_possible.at(0),
                      inner_state);
        }
        break;
      }
    }*/
  } 
}
bool EliminateInRow(const int &value, const int &row, Grid_t &inner_state) {
  for (size_t i = 0; i < inner_state.size(); i++) {
    std::vector<int> &possible_vec =
        inner_state[row][i].possible;  // use reference of possible cuz I'm lazy
    if (possible_vec.size() != 0) {
      for (auto it = possible_vec.begin(); it != possible_vec.end(); ++it) {
        if (value == *it) {
          possible_vec.erase(it);
          if (possible_vec.size() == 1) {
            return AssignValue(row, i, possible_vec.at(0), inner_state);
          }
          break;
        }
      }
    }
  }
  return true;
}

bool EliminateInCol(const int &value, const int &col, Grid_t &inner_state) {
  for (size_t i = 0; i < inner_state.size(); i++) {
    std::vector<int> &possible_vec =
        inner_state[i][col].possible;  // use reference cuz I'm lazy
    if (possible_vec.size() == 0) {
      continue;
    }
    for (auto it = possible_vec.begin(); it != possible_vec.end(); ++it) {
      if (value == *it) {
        possible_vec.erase(it);
        if (possible_vec.size() == 1) {
          return AssignValue(i, col, possible_vec.at(0), inner_state);
        }
        break;
      }
    }
  }
  return true;
}

// Eliminate value in box
bool EliminateInBox(const int &value, const int &row, const int &col,
                    Grid_t &inner_state) {
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
            return AssignValue(box_row + i, box_col + j, temp_vec->at(0),
                               inner_state);
          }
          break;
        }
      }
    }
  }
  return true;
}

// Find the cell with lowest number of peers
void FindMinPeers(size_t &min_row, size_t &min_col, const Grid_t &inner_state) {
  size_t min_possible = 9;
  for (size_t row = 0; row < inner_state.size(); row++) {
    for (size_t col = 0; col < inner_state[0].size(); col++) {
      const std::vector<int> &possible_vec = inner_state[row][col].possible;
      if (possible_vec.size() > 1) {
        if (possible_vec.size() < min_possible) {
          min_possible = possible_vec.size();
          min_row = row;
          min_col = col;
        }
      }
    }
  }
}
