#include "shape.hpp"
#include <iostream>

template <typename T1, typename T2>
void Compare( T1 &a,  T2 &b)  {
  if (a == b) {
    std::cout << "Equal" << std::endl;
  } else if ( a > b) {
    std::cout << "Bigger" << std::endl;
  } else {
    std::cout << "Smaller" << std::endl;
  }
}

int main() {
  Rectangle r1(1,2);
  Rectangle r2(3,3);
  Square s(3);
  Circle c(4);
  Compare(r1,s);
  Compare(s,r2);
  Compare(c,s);
  return 0;
}