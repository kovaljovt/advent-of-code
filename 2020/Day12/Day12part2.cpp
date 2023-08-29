#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <fstream>

struct Instructions {
    char letter;
    int number;
};

std::vector<Instructions> ParseInput(const std::string &file_path) {
    std::fstream input(file_path);
    std::string line;
    std::vector<Instructions> output;
    while (std::getline(input, line)) {
        output.push_back(Instructions {
                .letter = line[0],
                .number = std::stoi(line.substr(1, line.size() - 1))
        });
    }
    return output;
}


std::pair<int, int> wpChange(int xWp, int yWp, char direction, int degrees) {
    int xWpNew = 0;
    int yWpNew = 0;
    if (direction == 'L') {
        if (degrees == 90) {
            xWpNew = yWp * -1;
            yWpNew = xWp;
        } else if (degrees == 180) {
            xWpNew = xWp * -1;
            yWpNew = yWp * -1;
        } else if (degrees == 270) {
            xWpNew = yWp;
            yWpNew = xWp * -1;
        }
    } else if (direction == 'R') {
        if (degrees == 90) {
            xWpNew = yWp;
            yWpNew = xWp * -1;
        } else if (degrees == 180) {
            xWpNew = xWp * -1;
            yWpNew = yWp * -1;
        } else if (degrees == 270) {
            xWpNew = yWp * -1;
            yWpNew = xWp;
        }
    }
    return std::make_pair(xWpNew, yWpNew);
}


int part2() {
    std::vector<Instructions> data_input = ParseInput("/home/tibor/Desktop/advent-of-code/2020/Day12/Day12.txt");
    int xWp = 10;
    int yWp = 1;
    int xShip = 0;
    int yShip = 0;

    for (const auto &instruction : data_input) {
        if (instruction.letter == 'N') {
            yWp += instruction.number;
        } else if (instruction.letter == 'S') {
            yWp -= instruction.number;
        } else if (instruction.letter == 'E') {
            xWp += instruction.number;
        } else if (instruction.letter == 'W') {
            xWp -= instruction.number;
        } else if (instruction.letter == 'F') {
            xShip += instruction.number * xWp;
            yShip += instruction.number * yWp;
        } else if (instruction.letter == 'R' || instruction.letter == 'L') {
            std::tie(xWp, yWp) = wpChange(xWp, yWp, instruction.letter, instruction.number);
        }
    }

    return std::abs(xShip) + std::abs(yShip);
}


int main() {
    std::cout << part2() << '\n';
    return 0;
}