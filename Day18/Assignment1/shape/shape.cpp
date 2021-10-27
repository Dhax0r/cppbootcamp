#include "shape.hpp"
#include <iostream>

void Shape::Print() {
  std::cout << "Area: " << this->area_ << " Perimeter: " << this->perimeter_ << std::endl;
}

bool Shape::operator==(const Shape &s) {
  if (this->area_ == s.area_ && this->perimeter_ == s.perimeter_) {
    return true;
  } else {
    return false;
  }
}

bool Shape::operator>(const Shape &s) {
  if (this->area_ > s.area_ || (this->area_ == s.area_ && this->perimeter_ > s.perimeter_)){
      return true;
    } else {
      return false;
    }
}

bool Shape::operator<(const Shape &s) {
  if (this->area_ < s.area_ || (this->area_ == s.area_ && this->perimeter_ < s.perimeter_)){
      return true;
    } else {
      return false;
    }
}


Shape::~Shape(){}