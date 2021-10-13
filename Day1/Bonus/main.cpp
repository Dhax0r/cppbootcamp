#include <iostream>

int main() {
size_t upper = 128;
size_t lower = 1;

char answer;
int middle = lower + (upper - lower) / 2;
while(lower != upper) {
std::cout << "Is the number less or equal to " << upper;
std::cin >> answer;

  if (answer == 'y'){
    upper = upper/2;
  } else {
    lower = upper;
    upper *= 2;
  }
  middle = (upper + lower) / 2;
}

std::cout << "The answer is: " << lower << std::endl;


  return 0;
}