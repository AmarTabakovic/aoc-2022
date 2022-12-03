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
    bool exists_first[58] = {0};
    bool exists_second[58] = {0};

    for (int i = 0; i < s.length() / 2; i++) 
      exists_first[s[i] - 'A'] = true;

    for (int i = s.length() / 2; i < s.length(); i++)
      exists_second[s[i] - 'A'] = true;

    for (int i = 0; i < 58; i++) {
      if (exists_first[i] && exists_second[i]) {
        sum += i <= 25 ? i + 26 + 1 : i - 26 + 1 - 6;
        break;
      }
    }
  }

  std::cout << sum << std::endl;

  return 0;
}
