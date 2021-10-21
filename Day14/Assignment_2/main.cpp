#include <iostream>
#include <bitset>

struct SpeedAndDistance {
  unsigned speed : 4;
  unsigned front : 3;
  unsigned rear : 3;
  unsigned right : 3;
  unsigned left : 3;
};

uint16_t function2(unsigned int &, unsigned int &, unsigned int &,
                   unsigned int &, unsigned int &);

int main() {
  // 0b1011 = 11
  // 0b101 = 5
  // 0b001 = 1
  // 0b011 = 3
  // 0b011 = 3
  unsigned int speed = 11 * 20;
  unsigned int front = 5 * 150;
  unsigned int rear = 1 * 150;
  unsigned int right = 3 * 150;
  unsigned int left = 3 * 150;
  
  uint16_t a;
  a = function2(speed, front, rear, right, left);
  std::cout << std::bitset<16>(a) << std::endl;
  return 0;
}
uint16_t function2(unsigned int &speed, unsigned int &front, unsigned int &rear,
                   unsigned int &right, unsigned int &left) {
  uint16_t output = 0;
  SpeedAndDistance speed_distance;

  speed_distance.speed = (speed / 20);
  speed_distance.front = (front / 150);
  speed_distance.rear = (rear / 150);
  speed_distance.right = (right / 150);
  speed_distance.left = (left / 150);

  output = speed_distance.speed;
  output = output << 3 | speed_distance.front;
  output = output << 3 | speed_distance.rear;
  output = output << 3 | speed_distance.right;
  output = output << 3 | speed_distance.left;
  
  return output;
}