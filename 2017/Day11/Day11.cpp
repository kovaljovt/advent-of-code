#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <fstream>

std::vector<std::string> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::vector<std::string> output;
    std::string line;
    std::getline(input, line);
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ',')) {
        output.push_back(token);
    }
    return output;
}


int part1() {
    std::vector<std::string> data = parseInput("/home/tibor/Desktop/advent-of-code/2017/Day11/Day11.txt");
    std::vector<int> coords = {0, 0};
    int result = 0;
    for (const auto &direction: data) {
        if (direction == "n") {coords[0]++;}
        if (direction == "ne") {coords[1]++;}
        if (direction == "se") {coords[0]--, coords[1]++;}
        if (direction == "s") {coords[0]--;}
        if (direction == "sw") {coords[1]--;}
        if (direction == "nw") {coords[0]++, coords[1]--;}
        int x = coords[0];
        int z = coords[1];
        int y = -x-z;
        int distance = std::max(std::max(std::abs(x), std::abs(y)), std::abs(z));
        result = std::max(distance, 0);
    }
    return result;
}


int part2() {
    std::vector<std::string> data = parseInput("/home/tibor/Desktop/advent-of-code/2017/Day11/Day11.txt");
    std::vector<int> coords = {0, 0};
    int result = 0;
    for (const auto &direction: data) {
        if (direction == "n") {coords[0]++;}
        if (direction == "ne") {coords[1]++;}
        if (direction == "se") {coords[0]--, coords[1]++;}
        if (direction == "s") {coords[0]--;}
        if (direction == "sw") {coords[1]--;}
        if (direction == "nw") {coords[0]++, coords[1]--;}
        int x = coords[0];
        int z = coords[1];
        int y = -x-z;
        int distance = std::max(std::max(std::abs(x), std::abs(y)), std::abs(z));
        result = std::max(distance, result);
    }
    return result;
}


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}