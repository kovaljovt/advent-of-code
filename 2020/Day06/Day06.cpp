#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <string>

std::vector<std::string> parseInput(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::string> data;
    std::string line;
    while (getline(file, line)) {
        data.push_back(line);
    }
    return data;
}


int part1() {
    std::vector<std::string> data = parseInput("/home/tibor/Desktop/advent-of-code/2020/Day06/Day06.txt");
    int result = 0;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string groupAnswers = "";
    for (const auto &line : data) {
        if (line.empty()) {
            for (const auto &character : alphabet) {
                if (groupAnswers.find(character) != std::string::npos) {
                    result++;
                }
            }
            groupAnswers = "";
        } else {
            groupAnswers += line;
        }
    }
    for (const auto &character : alphabet) {
        if (groupAnswers.find(character) != std::string::npos) {
            result++;
        }
    }
    return result;
}


int part2() {
    std::vector<std::string> data = parseInput("/home/tibor/Desktop/advent-of-code/2020/Day06/Day06.txt");
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::set<char> groupAnswers;  // Store the answers for each group
    int result = 0;
    for (const auto &character : alphabet) {
        groupAnswers.insert(character);
    }
    for (const auto &line : data) {
        if (line.empty()) {
            result += groupAnswers.size();
            groupAnswers.clear();
            for (const auto &character : alphabet) {
                groupAnswers.insert(character);
            }
        } else {
            std::set<char> personAnswers;
            for (const auto &character : line) {
                personAnswers.insert(character);
            }
            std::set<char> commonAnswers;
            for (const auto &character : groupAnswers) {
                if (personAnswers.find(character) != personAnswers.end()) {
                    commonAnswers.insert(character);
                }
            }
            groupAnswers = commonAnswers;
        }
    }
    result += groupAnswers.size();
    return result;
}


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}