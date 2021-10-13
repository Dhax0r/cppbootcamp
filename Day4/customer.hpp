#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_
#include "payment.hpp"
#include "service_type.hpp"
#include <string>
class Customer {
  public:
    Customer(std::string name) :name_(name){}
    Customer(){}
    
    void AddService(ServiceType service_type);
    std::string GetName();
  
  private:
    //Date date_;
    //Part part_;
    ServiceType service_;
    //Payment payment_;
    int amount_;
    std::string name_;
};

#endif