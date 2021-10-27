#ifndef ELIMINATOR_HPP_
#define ELIMINATOR_HPP_
#include <string>
#include <vector>

typedef struct Cell {
  int value = -1;
  std::vector<int> possible = {1, 2, 3, 4, 5, 6, 7, 8, 9};

} Cell_t;
typedef std::vector<std::vector<Cell_t>> Grid_t;

void InitInner(Grid_t &inner_state,
               const int grid[9][9]);
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
bool IsValidRow(const size_t &row, const int &value,
                const Grid_t &inner_state);
bool IsValidCol(const size_t &col, const int &value,
                const Grid_t &inner_state);
bool IsValidBox(const size_t &row, const size_t &col, const int &value,
                const Grid_t &inner_state);
bool IsValid(const size_t &row, const size_t &col, const int &value,
             const Grid_t &inner_state);
void InitInner(const std::string &s,
               Grid_t &inner_state);
bool UniqueInRow(const int &value, const size_t &row, const size_t &col,
                 Grid_t inner_state);
bool UniqueInCol(const int &value, const size_t &row, const size_t &col,
                 const Grid_t &inner_state);
bool UniqueInBox(const int &value, const size_t &row, const size_t &col,
                 const Grid_t &inner_state);
void UniquePeer(Grid_t &inner_state);
#endif  // ELIMINATOR_HPP_