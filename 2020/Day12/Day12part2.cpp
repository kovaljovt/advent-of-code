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


std::pair<int, int> wpChange(int x_wp, int yWp, char direction, int degrees) {
    int xWpNew = 0;
    int yWp_new = 0;
    if (direction == 'L') {
        if (degrees == 90) {
            xWpNew = yWp * -1;
            yWp_new = x_wp;
        } else if (degrees == 180) {
            xWpNew = x_wp * -1;
            yWp_new = yWp * -1;
        } else if (degrees == 270) {
            xWpNew = yWp;
            yWp_new = x_wp * -1;
        }
    } else if (direction == 'R') {
        if (degrees == 90) {
            xWpNew = yWp;
            yWp_new = x_wp * -1;
        } else if (degrees == 180) {
            xWpNew = x_wp * -1;
            yWp_new = yWp * -1;
        } else if (degrees == 270) {
            xWpNew = yWp * -1;
            yWp_new = x_wp;
        }
    }
    return std::make_pair(xWpNew, yWp_new);
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
    std::cout << "The solution to day 12, part 2 is: " << part2() << '\n';
    return 0;
}