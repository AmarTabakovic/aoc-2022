#include <fstream>
#include <iostream>
#include <string>
#include <utility>
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

    int d1 = b - a;
    int d2 = d - c;

    if (d2 <= d1 && a <= c && b >= d || d1 <= d2 && c <= a && d >= b) sum++;
  }

  std::cout << sum << std::endl;

  return 0;
}
