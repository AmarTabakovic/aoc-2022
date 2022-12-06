#include <fstream>
#include <iostream>
#include <set>
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

  std::string input_line = buffer.at(0);

  int result = 0;
  int n = 14;

  for (int i = 0; i < input_line.length(); i++) {
    std::set<char> char_set;
    for (int j = i; j < i + n && j < input_line.length(); j++)
      char_set.insert(input_line[j]);

    if (char_set.size() == n) {
      result = i + n;
      i = input_line.length() + 1;
    }
  }

  std::cout << result << std::endl;

  return 0;
}
