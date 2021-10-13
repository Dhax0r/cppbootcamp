#ifndef WORKSHOP_HPP_
#define WORKSHOP_HPP_
#include "customer.hpp"
#include "record.hpp"

class Workshop {
  public:
    Workshop(){}
    void AddCustomer(const std::string);
    void PrintCustomers();
    void AddRecord(std::string, NameAndPrice, NameAndPrice);
    void AddRecord(const std::string);
    void AddRecord(std::string, Service);
    void AddRecord(std::string, NameAndPrice);

  private:
    Customer customers[100];
    Record records[100];

  public:
    Parts parts_;
    Services services_;

};

#endif