#include <iostream>
#include <set>

int main() {
  std::multiset<int> numbers;
  for (int i = 0; i < 1024; i++) {
    numbers.insert(std::rand());
  }

  int random_value = std::rand();

  auto upper = numbers.upper_bound(random_value);
  auto lower = numbers.lower_bound(random_value);
  lower--;

  std::cout << "Random value: " << random_value << " lower: " << *lower
            << " upper: " << *upper << std::endl;

  return 0;
}