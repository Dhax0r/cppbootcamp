#include "shape.hpp"
#include <iostream>

int main(int, char*[]){

  Circle c(3);
  Rectangle r(4,5);
  Square s(6,6);
  Rectangle r2(6,6);
  Shape *ptr[] = {&c, &r, &s, &r2};

  for (size_t j = 0; j < 3; j++){
    for(size_t k = j+1; k < 4; k++) {
      std::cout << "j: ";
      ptr[j]->Print();
      std::cout << "k: ";
      ptr[k]->Print();
      std::cout << "j is equal to k " << std::boolalpha << (*ptr[j] == *ptr[k]) << std::endl;
      std::cout << "j is greater than k " << std::boolalpha << (*ptr[j] > *ptr[k]) << std::endl;
      std::cout << "j is less than k " << std::boolalpha << (*ptr[j] < *ptr[k]) << std::endl;
    }
  }
  return 0;
}