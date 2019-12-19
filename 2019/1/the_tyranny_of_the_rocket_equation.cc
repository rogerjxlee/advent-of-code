#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int calculate_fuel(int mass) {
  return (mass / 3) - 2;
}

int calculate_total_fuel(int mass) {
  int total_fuel = 0;
  int fuel = calculate_fuel(mass);
  while (fuel > 0) {
    total_fuel += fuel;
    fuel = calculate_fuel(fuel);
  }
  return total_fuel;
}

int calculate_total_fuel(std::vector<int>& masses) {
  int total_fuel = 0;
  for (int mass : masses) {
    total_fuel += calculate_total_fuel(mass);
  }
  return total_fuel;
}

int main () {
  std::ifstream input_file;
  input_file.open("input.txt");
  std::string line;
  std::vector<int> input;
  if (input_file.is_open()) {
    while (std::getline(input_file, line)) {
      input.push_back(std::stoi(line));
    }
    input_file.close();
  }
  
  std::cout << calculate_total_fuel(input) << std::endl;
}
