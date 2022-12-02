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

  int total_score = 0;

  for (auto &s : buffer) {
    char enemy_choice = s.at(0);
    char my_choice = s.at(2);

    if (enemy_choice == my_choice - 23)
      total_score += 3 + my_choice - 'X' + 1;
    else if (my_choice == 'X' && enemy_choice == 'C' ||
             my_choice == 'Y' && enemy_choice == 'A' ||
             my_choice == 'Z' && enemy_choice == 'B') {
      total_score += 6 + my_choice - 'X' + 1;
    } else
      total_score += my_choice - 'X' + 1;
  }

  std::cout << total_score << std::endl;

  return 0;
}
