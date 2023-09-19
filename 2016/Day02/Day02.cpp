#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<std::string> data;
    while (std::getline(input, line)) {
        data.push_back(line);
    }
    return data;
}


int part1(const std::string &path) {
    std::vector<std::string> data = parseInput(path);
    std::vector<std::vector<int>> panel = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    int x = 1;
    int y = 1;
    std::string result = "";

    for(auto& line : data) {
        for(char p : line) {
            if(p == 'U') { y--; }
            else if(p == 'D') { y++; }
            else if(p == 'L') { x--; }
            else { x++; }

            if(x < 0) { x = 0;}
            if(x > 2) { x = 2;}
            if(y < 0) { y = 0;}
            if(y > 2) { y = 2;}
        }
        result += std::to_string(panel[y][x]);
    }

    return std::stoi(result);
}


std::string part2(const std::string &path) {
    std::vector<std::string> data = parseInput(path);
    std::vector<std::vector<char>> keypad = {
            {' ', ' ', '1', ' ', ' '},
            {' ', '2', '3', '4', ' '},
            {'5', '6', '7', '8', '9'},
            {' ', 'A', 'B', 'C', ' '},
            {' ', ' ', 'D', ' ', ' '}
    };

    int x = 0;
    int y = 2;
    std::string result;

    for (auto &line : data) {
        for (char p : line) {
            int new_x = x;
            int new_y = y;

            if (p == 'U') { new_y--; }
            else if (p == 'D') { new_y++; }
            else if (p == 'L') { new_x--; }
            else { new_x++; }

            if (new_x >= 0 && new_x < 5 && new_y >= 0 && new_y < 5 && keypad[new_y][new_x] != ' ') {
                x = new_x;
                y = new_y;
            }
        }
        result += keypad[y][x];
    }

    return result;
}


int main() {
    std::string path = R"(/home/tibor/Desktop/advent-of-code/2016/Day02/Day02.txt)";
    std::cout << part1(path) << '\n';
    std::cout << part2(path) << '\n';
    return 0;
}