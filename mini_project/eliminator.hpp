#ifndef ELIMINATOR_HPP_
#define ELIMINATOR_HPP_
#include <string>
#include <vector>
#include "grid.hpp"


void Solve(Grid_t &inner_state,
               const int grid[9][9]);
void Solve(const std::string &s,
               Grid_t &inner_state);
bool EliminateInRow(const int &value, const int &row,
                    Grid_t &inner_state);
bool EliminateInCol(const int &value, const int &col,
                    Grid_t &inner_state);
bool EliminateInBox(const int &value, const int &row, const int &col,
                    Grid_t &inner_state);
bool IsSolved(const Grid_t &inner_state);
bool AssignValue(const size_t &row, const size_t &col, const int &value,
                 Grid_t &inner_state);
void FindMinPeers(size_t &min_row, size_t &min_col,
                  const Grid_t &inner_state);
bool BruteForce(Grid_t &);

bool Eliminate(const size_t &row, const size_t &col, const int &value, Grid_t &inner_state);



#endif  // ELIMINATOR_HPP_