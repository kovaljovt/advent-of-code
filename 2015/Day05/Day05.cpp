#include <iostream>
#include <string>
#include <fstream>
#include <vector>

std::vector<std::string> parseInput(const std::string &filePath);
int part1();
int part2();


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}


std::vector<std::string> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<std::string> data;
    while(std::getline(input, line)) {
        data.push_back(line);
    }
    return data;
}


int part1() {
    std::vector<std::string> data = parseInput("/home/tibor/Desktop/advent-of-code/2015/Day05/Day05.txt");

    std::string vowels = "aeiou";
    std::vector<std::string> forbiddenSubString = {
            "ab", "cd", "pq", "xy"
    };
    int counter = 0;
    for (const auto& row : data) {
        int vowelCounter = 0;
        for (const auto& ch : row) {
            for (const auto& vowel : vowels) {
                if (vowel == ch) {
                    vowelCounter++;
                }
            }
        }

        bool notForbiddenSubString = false;

        for (const auto& subStr : forbiddenSubString) {
            size_t pos = row.find(subStr);
            if (pos != std::string::npos) { notForbiddenSubString = true; }
        }

        bool letterTwiceInRow = false;

        for (int i = 0; i < row.size();) {
            char ch = row[i];
            int num = 0;
            while (ch == row[i]) {
                i++;
                num++;
            }
            if (num >= 2) { letterTwiceInRow = true; break; }
        }

        if (vowelCounter >= 3 && !notForbiddenSubString && letterTwiceInRow) { counter++; }
    }
    return counter;
}


int part2() {
    std::vector<std::string> data = parseInput("/home/tibor/Desktop/advent-of-code/2015/Day05/Day05.txt");

    int counter = 0;

    for (const auto& row : data) {
        bool repeatedPairs = false;
        for (int i = 0; i < row.size(); i++) {
            if (i + 2 == row.size()) { break; }
            std::string subString = {row[i], row[i + 1]};
            size_t position = row.find(subString);
            if (position != std::string::npos) {
                if (position + 2 == row.size()) { break; }
                std::string anotherSubString = row.substr(position + 2);
                position = anotherSubString.find(subString);
                if (position != std::string::npos) {
                    repeatedPairs = true;
                }
            }
        }

        bool interleavedChar = false;

        for (int j = 0; j < row.size(); j++) {
            if (j + 2 == row.size()) { break; }
            if (row[j] == row[j + 2]) {
                interleavedChar = true;
            }
        }

        if (repeatedPairs && interleavedChar) {
            counter++;
        }
    }
    return counter;
}