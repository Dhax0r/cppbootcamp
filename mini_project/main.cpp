#include <iostream>
#include <iomanip>
#include <vector>
#include "solver.hpp"
#include "eliminator.hpp"
#include "print_sudoku.hpp"




int main() {
    
    
    //int box[3][3] = {{1, 2, 0},{4, 5, 6},{7, 8, 9}};
    
    int grid[9][9] = {
                    {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}
                    };
    /* int grid[9][9] = {
                    {7, 0, 3, 1, 0, 0, 9, 0, 4},
                    {4, 0, 5, 0, 0, 0, 0, 7, 3},
                    {0, 2, 0, 3, 0, 4, 1, 0, 5},
                    {6, 7, 0, 0, 3, 0, 0, 8, 9},
                    {0, 3, 1, 6, 4, 0, 0, 5, 0},
                    {0, 0, 0, 0, 2, 0, 0, 1, 0},
                    {0, 0, 0, 4, 0, 0, 2, 0, 8},
                    {0, 0, 6, 2, 0, 8, 5, 0, 0},
                    {0, 0, 4, 7, 5, 0, 6, 9, 0}
                    }; */
   
    Cell_t inner_state[9][9];
   
    //print_inner(inner_state);
    Print(grid);
    std::cout << "----------------------------------------" << std::endl;
    InitInner(inner_state, grid);
    Print(inner_state);

    if (Solve(grid)) {
        Print(grid);
    }
 
     
    return 0;
}


