#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int checksum(std::vector< std::vector<int> > spreadsheet) {
  int checksum = 0;
  int num_rows = spreadsheet.size();
  for (int r = 0; r < num_rows; r++) {
    std::vector<int> row = spreadsheet[r];
    std::vector<int>::iterator min_element = std::min_element(
      row.begin(), row.end());
    std::vector<int>::iterator max_element = std::max_element(
      row.begin(), row.end());
    int min = *min_element;
    int max = *max_element;
    checksum += max - min;
  }
  return checksum;
}

bool evenly_divisible(int x, int y) {
  return ((x % y == 0) || (y % x == 0));
}

int quotient(int x, int y) {
  if (x > y) {
    return (int) x / y;
  } else {
    return (int) y / x;
  }
}

int evenly_divisible_values(std::vector< std::vector<int> > spreadsheet) {
  int checksum = 0;
  int num_rows = spreadsheet.size();
  for (int r = 0; r < num_rows; r++) {
    std::vector<int> row = spreadsheet[r];
    for (std::vector<int>::iterator it = row.begin(); it != row.end(); it++) {
      for (std::vector<int>::iterator it2 = it + 1; it2 != row.end(); it2++) {
        if (evenly_divisible(*it, *it2)) {
          checksum += quotient(*it, *it2);
        }
      }
    }
  }
  return checksum;
}

int main() {
  std::ifstream input;
  input.open("input.txt");
  std::string line;
  std::vector< std::vector<int> > spreadsheet;
  while(std::getline(input, line)) {
    std::vector<int> row;
    std::stringstream ss(line);
    std::string cell;
    while(std::getline(ss, cell, '\t')) {
      row.push_back(std::stoi(cell, nullptr, 10));
    }
    spreadsheet.push_back(row);
  }

  std::cout << "Part 1: " << checksum(spreadsheet) << '\n';
  std::cout << "Part 2: " << evenly_divisible_values(spreadsheet) << '\n';
  return 0;
}
