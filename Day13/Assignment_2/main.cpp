#include <map>
#include <iostream>

int main() {
  std::map<int,int> numbers;
  
  for (int i = 0; i < 10000; i++) {
    int rand_value = std::rand()%34;
    auto search = numbers.find(rand_value);
    if (search != numbers.end()) {
      search->second++;
    } else {
      numbers[rand_value] = 1;
    }
  }
  // print the map of numbers and times it been duplicated
  for (auto p : numbers){
    std::cout << p.first << ": " << p.second << std::endl;
  }
  return 0;

}