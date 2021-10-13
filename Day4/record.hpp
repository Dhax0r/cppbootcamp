#ifndef RECORD_HPP_
#define RECORD_HPP_
#include <string>
#include "part.hpp"

class Record {
  public:
    Record(){}
    //Record(std::string reg_no, NameAndPrice part, NameAndPrice service);
    Record(std::string);
    //Record(std::string reg_no, Service service);
    void PrintRecord();
    int GetId();
    void SetReg(std::string);
    
  
  private:
    static int number_of_instances_;
    std::string reg_no_;
    Parts part_;
    Services service_;
    int CalculatePrice();

};


#endif