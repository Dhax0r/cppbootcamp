#ifndef _VALID_HPP_
#define _VALID_HPP_
#include "grid.hpp"

bool IsValidRow(const size_t &row, const int &value,
                const Grid_t &inner_state);
bool IsValidCol(const size_t &col, const int &value,
                const Grid_t &inner_state);
bool IsValidBox(const size_t &row, const size_t &col, const int &value,
                const Grid_t &inner_state);
bool IsValid(const size_t &row, const size_t &col, const int &value,
             const Grid_t &inner_state);
#endif // _VALID_HPP_