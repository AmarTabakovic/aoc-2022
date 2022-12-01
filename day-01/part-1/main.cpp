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

  int max_val = 0;
  int acc = 0;

  for (auto s : buffer) {
    if (s.empty()) {
      max_val = std::max(max_val, acc);
      acc = 0;
    } else
      acc += std::stoi(s);
  }

  std::cout << max_val << std::endl;

  return 0;
}
