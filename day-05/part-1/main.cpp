#include <fstream>
#include <iostream>
#include <stack>
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

  std::vector<std::stack<char>> stack_vec;

  for (int i = 0; i < 9; i++) stack_vec.push_back(std::stack<char>());

  for (int i = 8; i >= 0; i--) {
    for (int j = 1, x = 0; j < 36; j += 4, x++) {
      if (buffer.at(i)[j] >= 'A' && buffer.at(i)[j] <= 'Z') {
        stack_vec.at(x).push(buffer.at(i)[j]);
      }
    }
  }

  for (int i = 10; i < buffer.size(); i++) {
    int n;
    int from;
    int to;

    sscanf(buffer.at(i).c_str(), "move %d from %d to %d\n", &n, &from, &to);

    for (int j = 0; j < n; j++) {
      if (stack_vec.at(from - 1).empty()) break;
      char c = stack_vec.at(from - 1).top();
      stack_vec.at(from - 1).pop();
      stack_vec.at(to - 1).push(c);
    }
  }

  for (auto &s : stack_vec)
    if (!s.empty()) std::cout << s.top();

  std::cout << std::endl;

  return 0;
}
