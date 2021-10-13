#include "record.hpp"
#include <iostream>

//Record::Record(std::string reg_no, NameAndPrice part, NameAndPrice service)
  /* :reg_no_(reg_no), part_(part), service_(service)  {
  //  id_++;

}*/
Record::Record(std::string reg_no) {
  number_of_instances_++;
  this->reg_no_ = reg_no;
}
//Record::Record(std::string reg_no, )
int Record::CalculatePrice() {
  //int price = this->part_.price;
  //return price;
  return 0;
}
void Record::PrintRecord() {
  std::cout << "---------------------------------------------" << std::endl;
  //std::cout << "REG: " << this->reg_no_ << std::end;
  std::cout << "";
}
int Record::GetId() {
  return this->number_of_instances_;
} 

void Record::SetReg(std::string reg_no) {
  this->reg_no_ = reg_no;
}
