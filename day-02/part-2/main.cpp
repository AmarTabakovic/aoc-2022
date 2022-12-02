#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);

  std::vector<std::string> buffer;
  std::ifstream myfile("input.txt");
  std::string line;

  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      buffer.push_back(line);
    }
    myfile.close();
  }

  int total_result = 0;

  int result_table[3][3] = {
      {0 + 3, 0 + 1, 0 + 2}, 
      {3 + 1, 3 + 2, 3 + 3}, 
      {6 + 2, 6 + 3, 6 + 1}};

  for (auto &s : buffer) {
    char enemy_choice = s.at(0);
    char my_decision = s.at(2);
    total_result += result_table[my_decision - 'X'][enemy_choice - 'A'];
  }

  std::cout << total_result << std::endl;

  return 0;
}
