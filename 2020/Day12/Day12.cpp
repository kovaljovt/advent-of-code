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

int part1() {
    std::vector<Instructions> data = parseInput("/home/tibor/Desktop/advent-of-code/2020/Day12/Day12.txt");
    char currentDirection = 'E';
    int northSteps = 0;
    int southSteps = 0;
    int eastSteps = 0;
    int westSteps = 0;

    for (const auto &step : data) {
        // Direction
        if (step.letter == 'N') {
            northSteps += step.number;
        } else if (step.letter == 'S') {
            southSteps += step.number;
        } else if (step.letter == 'E') {
            eastSteps += step.number;
        } else if (step.letter == 'W') {
            westSteps += step.number;
        }

        // Rotating
        if (currentDirection == 'N') {
            if (step.letter == 'L' && step.number == 90)
                currentDirection = 'W';
            else if (step.letter == 'L' && step.number == 180)
                currentDirection = 'S';
            else if (step.letter == 'L' && step.number == 270)
                currentDirection = 'E';
            else if (step.letter == 'R' && step.number == 90)
                currentDirection = 'E';
            else if (step.letter == 'R' && step.number == 180)
                currentDirection = 'S';
            else if (step.letter == 'R' && step.number == 270)
                currentDirection = 'W';
        } else if (currentDirection == 'S') {
            if (step.letter == 'L' && step.number == 90)
                currentDirection = 'E';
            else if (step.letter == 'L' && step.number == 180)
                currentDirection = 'N';
            else if (step.letter == 'L' && step.number == 270)
                currentDirection = 'W';
            else if (step.letter == 'R' && step.number == 90)
                currentDirection = 'W';
            else if (step.letter == 'R' && step.number == 180)
                currentDirection = 'N';
            else if (step.letter == 'R' && step.number == 270)
                currentDirection = 'E';
        } else if (currentDirection == 'E') {
            if (step.letter == 'L' && step.number == 90)
                currentDirection = 'N';
            else if (step.letter == 'L' && step.number == 180)
                currentDirection = 'W';
            else if (step.letter == 'L' && step.number == 270)
                currentDirection = 'S';
            else if (step.letter == 'R' && step.number == 90)
                currentDirection = 'S';
            else if (step.letter == 'R' && step.number == 180)
                currentDirection = 'W';
            else if (step.letter == 'R' && step.number == 270)
                currentDirection = 'N';
        } else if (currentDirection == 'W') {
            if (step.letter == 'L' && step.number == 90)
                currentDirection = 'S';
            else if (step.letter == 'L' && step.number == 180)
                currentDirection = 'E';
            else if (step.letter == 'L' && step.number == 270)
                currentDirection = 'N';
            else if (step.letter == 'R' && step.number == 90)
                currentDirection = 'N';
            else if (step.letter == 'R' && step.number == 180)
                currentDirection = 'E';
            else if (step.letter == 'R' && step.number == 270)
                currentDirection = 'S';
        }

        // Forward
        if (step.letter == 'F') {
            if (currentDirection == 'N') {
                northSteps += step.number;
            } else if (currentDirection == 'S') {
                southSteps += step.number;
            } else if (currentDirection == 'E') {
                eastSteps += step.number;
            } else if (currentDirection == 'W') {
                westSteps += step.number;
            }
        }
    }

    int result = std::abs(eastSteps - westSteps) + std::abs(northSteps - southSteps);
    return result;
}

int main() {
    std::cout << part1() << '\n';
    return 0;
}