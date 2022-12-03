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

  for (int i = 0; i < buffer.size(); i += 3) {
    bool exists_first[58] = {0};
    bool exists_second[58] = {0};
    bool exists_third[58] = {0};

    for (int j = 0; j < buffer[i].length(); j++)
      exists_first[buffer[i][j] - 'A'] = true;

    for (int j = 0; j < buffer[i + 1].length(); j++)
      exists_second[buffer[i + 1][j] - 'A'] = true;

    for (int j = 0; j < buffer[i + 2].length(); j++)
      exists_third[buffer[i + 2][j] - 'A'] = true;

    for (int j = 0; j < 58; j++) {
      if (exists_first[j] && exists_second[j] && exists_third[j]) {
        sum += j <= 25 ? j + 26 + 1 : j - 26 + 1 - 6;
        break;
      }
    }
  }

  std::cout << sum << std::endl;

  return 0;
}
