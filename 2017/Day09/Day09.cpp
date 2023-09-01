#include <iostream>
#include <string>
#include <fstream>

std::string parseInput(const std::string &filePath) {
    std::ifstream input(filePath);
    std::string line;
    std::string data;
    while (std::getline(input, line)) {
        data += line;
    }
    return data;
}


int part1(const std::string &data) {
    int depth = 0;
    int result = 0;
    bool ignore = false;
    bool garbage = false;
    for (auto it = data.begin(); it != data.end(); ++it) {
        char character = *it;
        if (ignore) {
            ignore = false;
        } else if (character == '!') {
            ignore = true;
        } else if (character == '>') {
            garbage = false;
        } else if (garbage) {
            // Process garbage character (if needed)
        } else if (character == '<') {
            garbage = true;
        } else if (character == '{') {
            depth++;
        } else if (character == '}') {
            result += depth;
            depth--;
        }
    }
    return result;
}


int part2(const std::string &data) {
    int result = 0;
    bool garbage = false;
    bool ignore = false;
    for (auto it = data.begin(); it != data.end(); ++it) {
        char character = *it;
        if (ignore) {
            ignore = false;
        } else if (character == '!') {
            ignore = true;
        } else if (garbage) {
            if (character == '>') {
                garbage = false;
            } else {
                result++;
            }
        } else if (character == '<') {
            garbage = true;
        }
    }
    return result;
}


int main() {
    std::string data = parseInput("/home/tibor/Desktop/advent-of-code/2017/Day09/Day09.txt");
    std::cout << part1(data) << '\n';
    std::cout << part2(data) << '\n';
    return 0;
}
