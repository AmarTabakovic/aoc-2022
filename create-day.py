import os
import sys

MAKEFILE_CONTENT = 'all:\n\tg++ -std=c++14 main.cpp -o main -Ofast\n'
MAIN_CONTENT = """#include <iostream>
#include <fstream>
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

  return 0;
}
"""
GITIGNORE_CONTENT = 'main\n'

if len(sys.argv) != 2:
    print('Please enter the day.')
    exit(1)

day_nr = None

try:
    day_nr = int(sys.argv[1])
except ValueError:
    print('Not a number.')
    exit(1)

# Day exceeds 25
if (day_nr > 25):
    print('Cannot go beyond the 25th day.')
    exit(1)

# Create the day directory
try:
    day_dir = f'day-{day_nr:02d}'
    os.mkdir(day_dir)
    for i in range(1, 3):
        problem_dir = f'{day_dir}/part-{i}'
        os.mkdir(problem_dir)
except OSError as error:
    print(error)
    exit(1)

for i in range(1,3):
# Create main.cpp
    with open(f'{day_dir}/part-{i}/main.cpp', 'w') as file:
        file.write(MAIN_CONTENT)

    # Create Makefile
    with open(f'{day_dir}/part-{i}/Makefile', 'w') as file:
        file.write(MAKEFILE_CONTENT)

    # Create .gitignore
    with open(f'{day_dir}/part-{i}/.gitignore', 'w') as file:
        file.write(GITIGNORE_CONTENT)

print(f'Successfully created day {day_nr}')
