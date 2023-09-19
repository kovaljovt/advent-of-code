#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <climits>
#include <string>
#include <fstream>

std::vector<std::vector<std::string>> parseInput(const std::string &filePath) {
    std::ifstream input(filePath);
    std::string line;
    std::vector<std::vector<std::string>> data;
    while (std::getline(input, line)) {
        std::istringstream ss(line);
        std::string direction;
        std::vector<std::string> lineData;
        while (std::getline(ss, direction, ',')) {
            lineData.push_back(direction);
        }
        data.push_back(lineData);
    }
    return data;
}


int part1(const std::string &path) {
    std::vector<std::vector<std::string>> data = parseInput(path);
    std::vector<std::pair<int, int>> wireOneCoords;
    std::map<std::pair<int, int>, bool> wireTwoCoords = {};
    int result = INT_MAX;

    int x = 0;
    int y = 0;

    for (auto step: data[0]) {
        char direction = step[0];
        int distance = std::stoi(step.substr(1));
        for (int j = 0; j < distance; j++) {
            if (direction == 'U') { y++; }
            else if (direction == 'D') { y--; }
            else if (direction == 'R') { x++; }
            else { x--; }
            wireOneCoords.emplace_back(x, y);
        }
    }

    x = 0;
    y = 0;

    for (auto step : data[1]) {
        char direction = step[0];
        int distance = std::stoi(step.substr(1));
        for (int j = 0; j < distance; j++) {
            if (direction == 'U') { y++; }
            else if (direction == 'D') { y--; }
            else if (direction == 'R') { x++; }
            else { x--; }
            wireTwoCoords.insert({{x, y}, false});
        }
    }

    for(auto& step : wireOneCoords) {
        if(wireTwoCoords.find(step) != wireTwoCoords.end()) {
            int manhattanDistance = std::abs(step.first) + std::abs(step.second);
            result = std::min(result, manhattanDistance);
        }
    }

    return result;
}


int part2(const std::string &path) {
    std::vector<std::vector<std::string>> data = parseInput(path);
    std::map<std::pair<int, int>, int> wireOneCoords;
    std::map<std::pair<int, int>, int> wireTwoCoords;

    int x = 0;
    int y = 0;
    int steps1 = 0;

    for (auto step : data[0]) {
        char direction = step[0];
        int distance = std::stoi(step.substr(1));
        for (int j = 0; j < distance; j++) {
            if (direction == 'U') { y++; }
            else if (direction == 'D') { y--; }
            else if (direction == 'R') { x++; }
            else { x--; }
            steps1++;
            std::pair<int, int> coordinate = {x, y};
            if (wireOneCoords.find(coordinate) == wireOneCoords.end()) {
                wireOneCoords[coordinate] = steps1;
            }
        }
    }

    x = 0;
    y = 0;
    int steps2 = 0;
    int result = INT_MAX;

    for (auto step : data[1]) {
        char direction = step[0];
        int distance = std::stoi(step.substr(1));
        for (int j = 0; j < distance; j++) {
            if (direction == 'U') { y++; }
            else if (direction == 'D') { y--; }
            else if (direction == 'R') { x++; }
            else { x--; }
            steps2++;
            std::pair<int, int> coordinate = {x, y};
            if (wireTwoCoords.find(coordinate) == wireTwoCoords.end()) {
                wireTwoCoords[coordinate] = steps2;
            }
            // Check for intersection
            if (wireOneCoords.find(coordinate) != wireOneCoords.end()) {
                int combinedSteps = wireOneCoords[coordinate] + steps2;
                result = std::min(result, combinedSteps);
            }
        }
    }

    return result;
}


int main() {
    std::string path = R"(/home/tibor/Desktop/advent-of-code/2019/Day03/Day03.txt)";
    std::cout << part1(path) << '\n';
    std::cout << part2(path) << '\n';
    return 0;
}