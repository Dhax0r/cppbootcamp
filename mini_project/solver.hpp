#ifndef SOLVER_HPP_
#define SOLVER_HPP_

#include <iostream>
#include <vector>



bool IsValueInRow(int grid[9][9], int row, int number);
bool IsValueInCol(int grid[9][9], int col, int number) ;
bool IsValueInBox(int *row, int *col, int number);
bool IsValueInBox(int grid[9][9], int row, int col, int number);
bool FindEmptyCell(int grid[9][9], int &row, int &col);
bool Solve(int grid[9][9]);




#endif