#include "eliminator.hpp"
#include "print_sudoku.hpp"
#include <iomanip>
#include <iostream>


void InitInner(Grid_t &inner_state,
               const int grid[9][9]) {
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

void InitInner(const std::string &s, Grid_t &inner_state) {
  for (size_t i = 0; i < s.size(); i++) {
    size_t r = i/9;
    size_t c = i%9;
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
  if (!IsValid(row, col, value, inner_state)) {
    return false;
  }
  
  inner_state[row][col].value = value;
  inner_state[row][col].possible.clear();
  EliminateInRow(value, row, inner_state); 
  EliminateInCol(value, col, inner_state);
  EliminateInBox(value, row, col, inner_state);
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

bool EliminateInRow(const int &value, const int &row,
                    Grid_t &inner_state) {
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
bool EliminateInCol(const int &value, const int &col,
                    Grid_t &inner_state) {
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

// Find the cell with lowest number of peers
void FindMinPeers(size_t &min_row, size_t &min_col,
                  const Grid_t &inner_state) {
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

bool IsValid(const size_t &row, const size_t &col, const int &value,
             const Grid_t &inner_state) {
  return IsValidRow(row, value, inner_state) &&
         IsValidCol(col, value, inner_state) &&
         IsValidBox(row, col, value, inner_state);
}