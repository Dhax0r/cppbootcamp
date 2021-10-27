#ifndef _UNIQUE_HPP_
#define _UNIQUE_HPP_
#include "grid.hpp"

bool UniqueInRow(const int &value, const size_t &row, const size_t &col,
                 Grid_t inner_state);
bool UniqueInCol(const int &value, const size_t &row, const size_t &col,
                 const Grid_t &inner_state);
bool UniqueInBox(const int &value, const size_t &row, const size_t &col,
                 const Grid_t &inner_state);
void UniquePeer(Grid_t &inner_state);

#endif // _UNIQUE_HPP_