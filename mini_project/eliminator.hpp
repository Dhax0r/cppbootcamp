#ifndef ELIMINATOR_HPP_
#define ELIMINATOR_HPP_
#include <string>
#include <vector>

typedef struct Cell {
  int value = -1;
  std::vector<int> possible = {1, 2, 3, 4, 5, 6, 7, 8, 9};

} Cell_t;

void InitInner(std::vector<std::vector<Cell_t>> &inner_state,
               const int grid[9][9]);
bool EliminateInRow(const int &value, const int &row,
                    std::vector<std::vector<Cell_t>> &inner_state);
bool EliminateInCol(const int &value, const int &col,
                    std::vector<std::vector<Cell_t>> &inner_state);
bool EliminateInBox(const int &value, const int &row, const int &col,
                    std::vector<std::vector<Cell_t>> &inner_state);
bool IsSolved(const std::vector<std::vector<Cell_t>> &inner_state);
bool AssignValue(const size_t &row, const size_t &col, const int &value,
                 std::vector<std::vector<Cell_t>> &inner_state);
void FindMinPeers(size_t &min_row, size_t &min_col,
                  const std::vector<std::vector<Cell_t>> &inner_state);
bool BruteForce(std::vector<std::vector<Cell_t>> &);
bool IsValidRow(const size_t &row, const int &value,
                const std::vector<std::vector<Cell_t>> &inner_state);
bool IsValidCol(const size_t &col, const int &value,
                const std::vector<std::vector<Cell_t>> &inner_state);
bool IsValidBox(const size_t &row, const size_t &col, const int &value,
                const std::vector<std::vector<Cell_t>> &inner_state);
bool IsValid(const size_t &row, const size_t &col, const int &value,
             const std::vector<std::vector<Cell_t>> &inner_state);
void InitInner(const std::string &s,
               std::vector<std::vector<Cell_t>> &inner_state);
bool UniqueInRow(const int &value, const size_t &row, const size_t &col,
                 std::vector<std::vector<Cell_t>> inner_state);
bool UniqueInCol(const int &value, const size_t &row, const size_t &col,
                 const std::vector<std::vector<Cell_t>> &inner_state);
bool UniqueInBox(const int &value, const size_t &row, const size_t &col,
                 const std::vector<std::vector<Cell_t>> &inner_state);
#endif  // ELIMINATOR_HPP_