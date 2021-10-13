#include "solver.hpp"
#include <iomanip>

bool IsValueInRow(int grid[9][9], int row, int number) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i] == number)
            return true;
    }
    return false;
}

bool IsValueInCol(int grid[9][9], int col, int number) {
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == number)
            return true;
    }
    return false;
}

bool IsValueInBox(int grid[9][9], int row, int col, int number) {
    int box_row = row - row % 3;
    int box_col = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[box_row + i][box_col + j] == number)
                return true;   
        }
    }
   
    return false;
}



bool FindEmptyCell(int grid[9][9], int &row, int &col) {
    for (row = 0; row < 9; row++){
        for(col = 0; col < 9; col++) {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool Solve(int grid[9][9]) {
    int row, col;
    if(!FindEmptyCell(grid, row, col))
        return true;
    for (int number = 1; number < 10; number++) {
        if (!IsValueInRow(grid, row, number) && !IsValueInCol(grid, col, number) && !IsValueInBox(grid, row, col, number)) {
            grid[row][col] = number;
            if (Solve(grid)) {
                return true;
            } else {
                grid[row][col] = 0;
            }
        } 
    }
    return false;
}






