#include <iostream>

int main() {
size_t upper = 128;
size_t lower = 1;

char answer;
int middle = (upper + lower) / 2;
while(lower <= upper) {
std::cout << "Is the number less or equal to " << middle;
std::cin >> answer;

  if (answer == 'y'){
    upper = middle - 1;
  } else {
    lower = middle + 1;
    
  }
  middle = (upper + lower) / 2;
}

std::cout << "The answer is: " << lower << std::endl;


  return 0;
}