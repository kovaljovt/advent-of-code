#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

std::string parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string output;
    std::getline(input, output);
    return output;
}


int part1() {
    std::string data = parseInput("/home/tibor/Desktop/advent-of-code/2018/Day05/Day05.txt");
    std::string reactedPolymer;
    for (const auto &unit: data) {
        if (!reactedPolymer.empty() &&
            std::abs(unit - reactedPolymer.back()) == 32) {
            reactedPolymer.pop_back();
        } else {
            reactedPolymer.push_back(unit);
        }
    }
    int result = reactedPolymer.size();
    return result;
}


int part2() {
    std::string data = parseInput("/home/tibor/Desktop/advent-of-code/2018/Day05/Day05.txt");
    return 0;
}


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}