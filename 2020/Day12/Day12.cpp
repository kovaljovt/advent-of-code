#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

struct Instructions {
    char letter;
    int number;
};

std::vector<Instructions> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
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

char rotateDirection(char currentDirection, char rotation, int degrees) {
    const std::string directions = "NESW";
    int currentIndex = directions.find(currentDirection);
    int rotationIndex = degrees / 90;
    if (rotation == 'L') {
        currentIndex = (currentIndex - rotationIndex + 4) % 4;
    } else if (rotation == 'R') {
        currentIndex = (currentIndex + rotationIndex) % 4;
    }
    return directions[currentIndex];
}

void moveShip(int &northSteps, int &eastSteps, char direction, int steps) {
    if (direction == 'N') {
        northSteps += steps;
    } else if (direction == 'S') {
        northSteps -= steps;
    } else if (direction == 'E') {
        eastSteps += steps;
    } else if (direction == 'W') {
        eastSteps -= steps;
    }
}

int part1() {
    std::vector<Instructions> data = parseInput("/home/tibor/Desktop/advent-of-code/2020/Day12/Day12.txt");
    char currentDirection = 'E';
    int northSteps = 0;
    int eastSteps = 0;

    for (const auto &step : data) {
        if (step.letter == 'F') {
            moveShip(northSteps, eastSteps, currentDirection, step.number);
        } else if (step.letter == 'R' || step.letter == 'L') {
            currentDirection = rotateDirection(currentDirection, step.letter, step.number);
        } else {
            moveShip(northSteps, eastSteps, step.letter, step.number);
        }
    }

    int result = std::abs(northSteps) + std::abs(eastSteps);
    return result;
}

int main() {
    std::cout << part1() << '\n';
    return 0;
}
