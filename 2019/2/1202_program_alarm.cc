#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> split(std::string input, char delimiter) {
  std::vector<int> output;
  int position = 0;
  int length = 0;
  while (position + length < input.size()) {
    if (input[position + length] == delimiter) {
      output.push_back(std::stoi(input.substr(position, length)));
      position += length + 1;
      length = 0;
    }
    length++;
  }
  output.push_back(std::stoi(input.substr(position, length)));
  return output;
}

void add(std::vector<int>& intcode_program, int& instruction_pointer) {
  int input_index1 = intcode_program[instruction_pointer + 1];
  int input_index2 = intcode_program[instruction_pointer + 2];
  int output_index = intcode_program[instruction_pointer + 3];
  intcode_program[output_index] =
      intcode_program[input_index1] + intcode_program[input_index2];
  instruction_pointer += 4;
}

void multiply(std::vector<int>& intcode_program, int& instruction_pointer) {
  int input_index1 = intcode_program[instruction_pointer + 1];
  int input_index2 = intcode_program[instruction_pointer + 2];
  int output_index = intcode_program[instruction_pointer + 3];
  intcode_program[output_index] =
      intcode_program[input_index1] * intcode_program[input_index2];
  instruction_pointer += 4;
}

int run(std::vector<int> intcode_program, int noun, int verb) {
  intcode_program[1] = noun;
  intcode_program[2] = verb;
  int instruction_pointer = 0;
  bool proceed = true;
  while (proceed) {
    switch (intcode_program[instruction_pointer]) {
      case 1:
        add(intcode_program, instruction_pointer);
        break;
      case 2:
        multiply(intcode_program, instruction_pointer);
        break;
      case 99:
        proceed = false;
        break;
    }
  }
  return intcode_program[0];
}

struct Input {
  int noun;
  int verb;
};

Input get_input(std::vector<int> intcode_program, int target_output) {
  for (int noun = 0; noun < 100; noun++) {
    for (int verb = 0; verb < 100; verb++) {
      if (run(intcode_program, noun, verb) == target_output) {
        return Input{noun, verb};
      }
    }
  }
  return Input{-1, -1};
}

int main() {
  std::ifstream input_file;
  input_file.open("input.txt");
  std::string line;
  std::vector<int> input;
  if (input_file.is_open()) {
    while (std::getline(input_file, line)) {
      input = split(line, ',');
    }
    input_file.close();
  }
  std::vector<int> intcode_program = input;
  std::cout << run(intcode_program, 12, 2) << std::endl;
  Input intcode_input = get_input(intcode_program, 19690720);
  std::cout << 100 * intcode_input.noun + intcode_input.verb << std::endl;
}
