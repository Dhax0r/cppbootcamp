#include <bitset>
#include <iostream>

struct States {
  unsigned lights : 3;
  unsigned doors : 4;
  unsigned windows : 4;
  unsigned seat_belts : 5;
  
};

void function(uint16_t &);

int main() {
  uint16_t states = 0b1011101001011011;
  function(states);
  
  return 0;
}

void function(uint16_t &input) {

  States *state = reinterpret_cast<States*>(&input);

  for (size_t i = 1, j = 1; i <= 0x10; i <<= 1, j++){
    std::cout << "seat belt " << j  << " is ";
    if (!(state->seat_belts & i)) {
      std::cout << "not ";
    }
    std::cout << "buckled" << std::endl;
  }
  for (size_t i = 1, j = 1; i <= 0x0F; i <<= 1, j++){
    std::cout << "window " << j  << " is ";
    if (!(state->windows & i)) {
      std::cout << "not ";
    }
    std::cout << "open" << std::endl;
  }
  for (size_t i = 1, j = 1; i <= 0x0F; i <<= 1, j++){
    std::cout << "door " << j  << " is ";
    if (!(state->doors & i)) {
      std::cout << "not ";
    }
    std::cout << "open" << std::endl;
  }
  for (size_t i = 1, j = 1; i <= 0x07; i <<= 1, j++){
    std::cout << "light " << j  << " is ";
    if (!(state->lights & i)) {
      std::cout << "not ";
    }
    std::cout << "on" << std::endl;
  }
}

