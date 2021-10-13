#ifndef PART_HPP_
#define PART_HPP_
#include <string>

/* struct NameAndPrice {
  std::string name;
  int price;
};

struct Parts {
  NameAndPrice engine =  {"Engine", 50000};
  NameAndPrice headlamps = {"Headlamps", 5000};
  NameAndPrice wiperblades = {"Wiperblades", 250};
};

struct Services {
  NameAndPrice basic = {"Basic", 2000};
  NameAndPrice extended = {"Extended", 4500};
};

enum class Service {
  kBasic,
  kExtended
};
 */

enum class PartType {
  kEngine,
  kHeadlamps,
  kWipermotor
};

class Part {
  public:
    Part(const PartType &t):part_type_(t){}
    double GetCost();
  private:
    PartType part_type_;
    double part_price_;
};




#endif