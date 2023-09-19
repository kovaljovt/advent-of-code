#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <fstream>

std::vector<std::vector<std::string>> parseInput(const std::string &filePath) {
    std::ifstream input(filePath);
    std::string line;
    std::vector<std::vector<std::string>> data;
    while (std::getline(input, line)) {
        std::vector<std::string> row;
        std::istringstream ss(line);
        std::string str;
        while (std::getline(ss, str, ',')) {
            row.push_back(str);
        }
        data.push_back(row);
    }

    return data;
}


int part1(const std::string &path) {
    std::vector<std::vector<std::string>> data = parseInput(path);
    int result = 0;

    for (const auto &passphrase: data) {
        std::unordered_map<std::string, bool> seen;
        bool isValid = true;
        for (const auto &word: passphrase) {
            if (seen[word]) {
                isValid = false;
                break;
            }
            seen[word] = true;
        }
        if (isValid) {
            result++;
        }
    }

    return result;
}


int part2(const std::string &path) {
    std::vector<std::vector<std::string>> data = parseInput(path);
    int result = 0;

    for (const auto &passphrase : data) {
        std::unordered_map<std::string, bool> seen;
        bool isValid = true;
        for (auto &word : passphrase) {
            std::string sortedWord = word;
            std::sort(sortedWord.begin(), sortedWord.end());
            if (seen[sortedWord]) {
                isValid = false;
                break;
            }
            seen[sortedWord] = true;
        }
        if (isValid) {
            result++;
        }
    }

    return result;
}


int main() {
    std::string path = R"(/home/tibor/Desktop/advent-of-code/2017/Day04/Day04.txt)";
    std::cout << part1(path) << '\n';
    std::cout << part2(path) << '\n';
    return 0;
}