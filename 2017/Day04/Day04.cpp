#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <fstream>

std::vector<std::string> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<std::string> output;
    while (std::getline(input, line)) {
        output.push_back(line);
    }
    return output;
}


std::string sortString(const std::string &str) {
    std::string sorted = str;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}


int part1() {
    std::vector<std::string> data = parseInput(
            R"(/home/tibor/Desktop/advent-of-code/2017/Day04/Day04.txt)"
    );
    int result = 0;
    for (const auto &line : data) {
        std::vector<std::string> words;
        std::string currentWord;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                words.push_back(currentWord);
                currentWord.clear();
            } else if (i == line.size() - 1) {
                currentWord += line[i];
                words.push_back(currentWord);
            } else {
                currentWord += line[i];
            }
        }
        bool invalid = false;
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (words[i] == words[j]) {
                    invalid = true;
                    break;
                }
            }
            if (invalid) {
                break;
            }
        }
        if (!invalid) {
            result++;
        }
    }
    return result;
}


int part2() {
    std::vector<std::string> data = parseInput(
            R"(/home/tibor/Desktop/advent-of-code/2017/Day04/Day04.txt)"
    );
    int result = 0;
    for (const auto &line : data) {
        std::unordered_map<std::string, int> wordCount;
        std::string currentWord;
        for (char c : line) {
            if (c == ' ') {
                wordCount[sortString(currentWord)]++;
                currentWord.clear();
            } else {
                currentWord += c;
            }
        }
        wordCount[sortString(currentWord)]++; // Count the last word in the line
        bool invalid = false;
        for (const auto &wordPair : wordCount) {
            if (wordPair.second > 1) {
                invalid = true;
                break;
            }
        }
        if (!invalid) {
            result++;
        }
    }
    return result;
}


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}