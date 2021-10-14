#include "eliminator.hpp"
#include <iostream>
#include <iomanip>

void InitInner(std::vector<std::vector<Cell_t>> &inner_state, const int grid[9][9]){
    int m = 0;
    while (m < 100 && !IsSolved(inner_state)) {
        for (size_t i = 0; i < inner_state.size(); i++) {
            for (size_t j = 0; j < inner_state[0].size(); j++) {
                int value = grid[i][j];
                if (value) {
                    inner_state[i][j].possible = {grid[i][j]};
                }
                if (inner_state[i][j].possible.size() == 1) {
                    EliminateInRow(inner_state[i][j].possible.at(0), i, inner_state);
                    EliminateInCol(inner_state[i][j].possible.at(0), j, inner_state);
                    EliminateInBox(inner_state[i][j].possible.at(0), i, j, inner_state);
                }
            }
        }
        m++;
    }
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
        if (inner_state[row][i].possible.size() != 1) {
            for (auto it = inner_state[row][i].possible.begin(); it != inner_state[row][i].possible.end(); ++it) {
                if (value == *it) {
                    inner_state[row][i].possible.erase(it);
                    break;
                }
            }
        }
    }
}
void EliminateInCol(const int &value, const int &col, std::vector<std::vector<Cell_t>> &inner_state) {
    for (size_t i = 0; i < inner_state.size(); i++) {
        if (inner_state[i][col].possible.size() == 1) {
            continue;
        }
        for (auto it = inner_state[i][col].possible.begin(); it != inner_state[i][col].possible.end(); ++it) {
            if (value == *it) {
                inner_state[i][col].possible.erase(it);
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
            if (temp_vec->size() == 1){
                continue;
            }
            for (auto it = temp_vec->begin(); it != temp_vec->end(); ++it) {
                if (value == *it) {
                    temp_vec->erase(it);
                    break;
                }
            }
        }
    }
}