#include "eliminator.hpp"
#include <iostream>
#include <iomanip>

void InitInner(std::vector<std::vector<Cell_t>> &inner_state, const int grid[9][9]){
    for (size_t i = 0; i < inner_state.size(); i++) {
        for (size_t j = 0; j < inner_state[0].size(); j++) {
            int value = grid[i][j];
            if (value) {
                AssignValue(i,j,value, inner_state);
            }
        }
    }
}

void AssignValue(const size_t &row, const size_t &col, const int &value, std::vector<std::vector<Cell_t>> &inner_state) {
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

void EliminateInRow(const int &value, const int &row, std::vector<std::vector<Cell_t>> &inner_state) {
    for (size_t i = 0; i < inner_state.size(); i++) {
        if (inner_state[row][i].possible.size() != 0) {
            for (auto it = inner_state[row][i].possible.begin(); it != inner_state[row][i].possible.end(); ++it) {
                if (value == *it) {
                    inner_state[row][i].possible.erase(it);
                    if (inner_state[row][i].possible.size() == 1) {
                        AssignValue(row,i,inner_state[row][i].possible.at(0),inner_state);
                    }
                    break;
                }
            }
        }
    }
}
void EliminateInCol(const int &value, const int &col, std::vector<std::vector<Cell_t>> &inner_state) {
    for (size_t i = 0; i < inner_state.size(); i++) {
        if (inner_state[i][col].possible.size() == 0) {
            continue;
        }
        for (auto it = inner_state[i][col].possible.begin(); it != inner_state[i][col].possible.end(); ++it) {
            if (value == *it) {
                inner_state[i][col].possible.erase(it);
                if (inner_state[i][col].possible.size() == 1) {
                    AssignValue(i, col, inner_state[i][col].possible.at(0), inner_state);
                }
                break;
            }
        }
    }
}
void EliminateInBox(const int &value, const int &row, const int &col, std::vector<std::vector<Cell_t>> &inner_state){
    int box_row = row - row % 3;
    int box_col = col - col % 3;
    for (size_t i = 0; i < 3; i++) {
        for (size_t j = 0; j < 3; j++) {
            std::vector<int> *temp_vec = &inner_state[box_row + i][box_col + j].possible;
            if (temp_vec->size() == 0){
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