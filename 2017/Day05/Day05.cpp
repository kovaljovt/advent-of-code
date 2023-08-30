#include <iostream>
#include <string>
#include <vector>
#include <fstream>

std::vector<std::string> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<int> output;
    while (std::getline(input, line)) {
        output.push_back(std::stoi(line));
    }
    return output;
}


int part1() {
    std::vector<int> data = parseInput("/home/tibor/Desktop/advent-of-code/2017/Day05/Day05.txt");
    int result = 0;
    int index = 0;
    while (index >= 0 && index < data.size()) {
        result++;
        data[index]++;
        index += data[index] - 1;
    }
    return result;
}


int part2() {
    std::vector<int> data = parseInput("/home/tibor/Desktop/advent-of-code/2017/Day05/Day05.txt");
    int result = 0;
    int index = 0;
    while (index >= 0 && index < data.size()) {
        result++;
        index += data[index] >= 3 ? data[index]-- : data[index]++;
    }
    return result;
}


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}