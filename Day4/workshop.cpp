#include "workshop.hpp"
#include <iostream>

void Workshop::AddCustomer(std::string name) {
  std::cout << "Adding customer" << std::endl;
  
  size_t number_of_customers = sizeof(this->customers)/sizeof(this->customers[0]);
  for (int i = 0; i < number_of_customers; i++) {
    if(customers[i].GetName() == "") {
      
      Customer c(name);
      customers[i] = c;
      std::cout << customers[i].GetName() << " added" << std::endl;
      break;
    }

  }
}

void Workshop::PrintCustomers() {
  size_t number_of_customers = sizeof(this->customers)/sizeof(this->customers[0]);
  for (int i = 0; i < number_of_customers; i++) {
    if (customers[i].GetName() == "") {
      break;
    } else {
      std::cout << customers[i].GetName() << std::endl;
    }
  }
}
void AddRecord(std::string reg_no, NameAndPrice part, NameAndPrice service) {
  

}

void Workshop::AddRecord(const std::string reg_no) {
  
  std::cout << records[0].GetId() << std::endl;
  this->records[0] = Record(reg_no); 

}