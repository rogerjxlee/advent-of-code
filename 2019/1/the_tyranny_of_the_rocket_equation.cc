#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int calculate_fuel(int mass) { return (mass / 3) - 2; }

int calculate_total_fuel(int mass) {
  int total_fuel = 0;
  int fuel = calculate_fuel(mass);
  while (fuel > 0) {
    total_fuel += fuel;
    fuel = calculate_fuel(fuel);
  }
  return total_fuel;
}

int part1(const std::vector<int>& module_masses) {
  return std::accumulate(
      module_masses.begin(), module_masses.end(), 0,
      [](int x, int y) -> int { return x + calculate_fuel(y); });
}

int part2(const std::vector<int>& module_masses) {
  return std::accumulate(
      module_masses.begin(), module_masses.end(), 0,
      [](int x, int y) -> int { return x + calculate_total_fuel(y); });
}

std::string get_file_contents(std::string filename) {
  std::ifstream file(filename);
  std::string file_contents((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
  return file_contents;
}

std::vector<int> split(std::string input, char delimiter) {
  std::vector<int> output;
  int position = 0;
  int length = 0;
  while (position + length < input.size()) {
    if (input[position + length] == delimiter) {
      if (length > 0) {
        output.push_back(std::stoi(input.substr(position, length)));
        position += length + 1;
        length = 0;
      }
    } else {
      length++;
    }
  }
  if (length > 0) {
    output.push_back(std::stoi(input.substr(position, length)));
  }
  return output;
}

int main() {
  std::vector<int> input = split(get_file_contents("input.txt"), '\n');
  std::cout << "Part 1: " + std::to_string(part1(input)) << std::endl;
  std::cout << "Part 2: " + std::to_string(part2(input)) << std::endl;
}
