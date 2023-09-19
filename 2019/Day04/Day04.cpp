#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> parseInput() {
    std::string input = "272091-815432";
    std::istringstream iss(input);
    std::string firstNumber, secondNumber;
    std::string token;
    getline(iss, token, '-');
    firstNumber = token;
    getline(iss, token);
    secondNumber = token;
    return {firstNumber, secondNumber};
}


int part1() {
    std::vector<std::string> data = parseInput();
    int result = 0;

    int start = std::stoi(data[0]);
    int end = std::stoi(data[1]);

    for (int i = start; i < end; i++) {
        std::string num = std::to_string(i);
        bool ruleBroken;

        ruleBroken = num.size() != 6;
        if(ruleBroken) {
            continue;
        }

        for(int j = 0; j < num.size() - 1; j++) {
            if(num[j] > num[j+1]) {
                ruleBroken = true;
                break;
            }
        }
        if(ruleBroken) { continue; }

        ruleBroken = true;
        for(int j = 0; j < num.size() - 1; j++) {
            if(num[j] == num[j+1]) {
                ruleBroken = false; break;
            }
        }

        if(!ruleBroken) { result++; }
    }

    return result;
}


bool hasValidDouble(std::string num) {
    int count = 1;
    for (int i = 1; i < num.size(); i++) {
        if (num[i] == num[i - 1]) {
            count++;
        } else {
            if (count == 2) {
                return true;
            }
            count = 1;
        }
    }
    return count == 2;
}


int part2() {
    std::vector<std::string> data = parseInput();
    int result = 0;

    int start = std::stoi(data[0]);
    int end = std::stoi(data[1]);

    for (int i = start; i <= end; i++) {
        std::string num = std::to_string(i);
        bool ruleBroken = false;

        if (num.size() != 6) {
            continue;
        }

        for (int j = 0; j < num.size() - 1; j++) {
            if (num[j] > num[j + 1]) {
                ruleBroken = true;
                break;
            }
        }
        if (ruleBroken) {
            continue;
        }

        if (!hasValidDouble(num)) {
            continue;
        }

        result++;
    }

    return result;
}


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}