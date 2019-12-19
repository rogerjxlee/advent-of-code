#include <iostream>
#include <fstream>

int check_circular_next(std::string digits) {
  int sum = 0;
  int size = digits.size();
  for (int i = 0; i < size; i++) {
    if (digits[i] == digits[(i + 1) % size]) {
      int value = digits[i] - '0';
      sum += value;
    }
  }
  return sum;
}

int check_circular_halfway_around(std::string digits) {
  int sum = 0;
  int size = digits.size();
  for (int i = 0; i < size; i++) {
    if (digits[i] == digits[(i + size / 2) % size]) {
      int value = digits[i] - '0';
      sum += value;
    }
  }
  return sum;
}

int main() {
  std::ifstream input;
  input.open("input.txt");
  std::string digits;
  std::getline(input, digits);
  std::cout << "Part 1: " << check_circular_next(digits) << '\n';
  std::cout << "Part 2: " << check_circular_halfway_around(digits) << '\n';
  return 0;
}
