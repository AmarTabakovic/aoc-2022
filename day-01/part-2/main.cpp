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

  int first = 0;
  int second = 0;
  int third = 0;
  int acc = 0;

  for (auto &s : buffer) {
    if (s.empty()) {
      if (acc > third && acc <= second) {
        third = acc;
      } else if (acc > second && acc <= first) {
        third = second;
        second = acc;
      } else if (acc > first) {
        third = second;
        second = first;
        first = acc;
      }
      acc = 0;
    } else
      acc += std::stoull(s);
  }
  std::cout << first + second + third << std::endl;
  return 0;
}