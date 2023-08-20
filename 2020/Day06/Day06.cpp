#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>

int main() {
    std::fstream input("/home/tibor/Desktop/advent of code/advent-of-code/2020/Day06/Day06.txt");
    std::string line;
    std::vector<std::string> data;

    while (std::getline(input, line)) {
        if (!line.empty())
            data.push_back(line);
    }



    return 0;
}