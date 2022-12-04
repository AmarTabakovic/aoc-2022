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

  int sum = 0;

  for (auto &s : buffer) {
    int a;
    int b;
    int c;
    int d;

    sscanf(s.c_str(), "%d-%d,%d-%d", &a, &b, &c, &d);

    if (a <= d && b >= c || a >= d && b <= c) sum++;
  }

  std::cout << sum << std::endl;

  return 0;
}
