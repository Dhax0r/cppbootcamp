#include <iostream>
#include <vector>
#include <chrono>

#include "solver.hpp"
#include "eliminator.hpp"
#include "print_sudoku.hpp"

int main() {
    const unsigned int rows = 9;
    const unsigned int cols = 9;

    /* int grid[9][9] = {
                    {3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}
                    }; */
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
/* int grid [9][9] = 
{{8,5,0,0,0,2,4,0,0},
 {7,2,0,0,0,0,0,0,9},
 {0,0,4,0,0,0,0,0,0},
 {0,0,0,1,0,7,0,0,2},
 {3,0,5,0,0,0,9,0,0},
 {0,4,0,0,0,0,0,0,0},
 {0,0,0,0,8,0,0,7,0},
 {0,1,7,0,0,0,0,0,0},
 {0,0,0,0,3,6,0,4,0}}; */

 int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0, 3, 0, 8, 5},
                    {0, 0, 1, 0, 2, 0, 0, 0, 0},
                    {0, 0, 0, 5, 0, 7, 0, 0, 0},
                    {0, 0, 4, 0, 0, 0, 1, 0, 0},
                    {0, 9, 0, 0, 0, 0, 0, 0, 0},
                    {5, 0, 0, 0, 0, 0, 0, 7, 3},
                    {0, 0, 2, 0, 1, 0, 0, 0, 0},
                    {0, 0, 0, 0, 4, 0, 0, 0, 9}};

// Super hard sudoku
/* int grid[9][9] = {{0 ,0, 0, 0, 0, 5, 0, 8, 0},
                  {0 ,0 ,0 ,6 ,0 ,1 ,0 ,4 ,3},
                  {0, 0, 0, 0, 0, 0, 0, 0, 0},
                  {0 ,1 ,0 ,5 ,0 ,0 ,0 ,0 ,0},
                  {0 ,0, 0, 1, 0, 6, 0, 0, 0},
                  {3 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,5},
                  {5 ,3, 0, 0, 0, 0, 0, 6, 1},
                  {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,4},
                  {0 ,0, 0, 0, 0, 0, 0, 0, 0}}; */

    Grid_t inner_state(
        rows, std::vector<Cell_t>(cols, Cell_t()));
    std::string s = "..6.9.2.....7.2....9.5.8.7.9...3...675.....191...4...5.1.3.9.8....2.1.....9.8.1..";
    Print(grid);
    std::cout << "----------------------------------------" << std::endl;
    auto start_time = std::chrono::high_resolution_clock::now();
    Solve(s, inner_state);
    auto end_time = std::chrono::high_resolution_clock::now();
    Print(inner_state);
    std::chrono::duration<double, std::milli> duration_time = end_time - start_time;
    std::cout << "sudoku solved in " << duration_time.count() << "ms"<< std::endl;
    
    /* auto start_time = std::chrono::high_resolution_clock::now();
    InitInner(inner_state, grid);
    auto end_time = std::chrono::high_resolution_clock::now();
    Print(inner_state); 

    std::chrono::duration<double, std::milli> duration_time = end_time - start_time;

    std::cout << "sudoku solved in " << duration_time.count() << "ms"<< std::endl;
    
    std::cout << "---old bruteforce---" << std::endl;
    start_time = std::chrono::high_resolution_clock::now();
    if (Solve(grid)) {
      end_time = std::chrono::high_resolution_clock::now();
      Print(grid);
      duration_time = end_time - start_time;
      std::cout << "sudoku solved in " << duration_time.count() << "ms" << std::endl;
    }
*/
    return 0;
}
