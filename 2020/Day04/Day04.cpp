#include <iostream>
#include <string>
#include <sstream>
#include <regex>
#include <unordered_set>
#include <vector>
#include <fstream>

std::vector<std::vector<std::string>> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<std::vector<std::string>> data;
    std::vector<std::string> passport;
    while (std::getline(input, line)) {
        if (line.empty()) {
            if (!passport.empty()) {
                data.push_back(passport);
                passport.clear();
            }
        } else {
            std::istringstream iss(line);
            std::string part;
            while (iss >> part) {
                passport.push_back(part);
            }
        }
    }
    if (!passport.empty()) {
        data.push_back(passport);
    }
    return data;
}


int part1(const std::string &path) {
    std::vector<std::vector<std::string>> data = parseInput(path);
    int result = 0;

    for (const auto &passport: data) {
        std::unordered_set<std::string> ids;
        for (const auto &field: passport) {
            size_t colonPosition = field.find(':');
            if (colonPosition != std::string::npos) {
                std::string id = field.substr(0, colonPosition);
                ids.insert(id);
            }
        }
        bool validPassport = true;
        std::vector<std::string> requiredFields = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
        for (const std::string &requiredField: requiredFields) {
            if (ids.find(requiredField) == ids.end()) {
                validPassport = false;
                break;
            }
        }
        if (validPassport) {
            result++;
        }
    }

    return result;
}

int part2(const std::string &path) {
    std::vector<std::vector<std::string>> data = parseInput(path);
    int result = 0;

    for (const auto &passport : data) {
        bool byr = false;
        bool iyr = false;
        bool eyr = false;
        bool hgt = false;
        bool hcl = false;
        bool ecl = false;
        bool pid = false;
        for (const auto &field : passport) {
            auto colonPosition = field.find(':');
            std::string id = field.substr(0, colonPosition);
            std::string value = field.substr(colonPosition + 1);
            if (id == "byr") {
                int birthYear = std::stoi(value);
                if (birthYear >= 1920 && birthYear <= 2002) {
                    byr = true;
                }
            }
            if (id == "iyr") {
                int issueYear = std::stoi(value);
                if (issueYear >= 2010 && issueYear <= 2020) {
                    iyr = true;
                }
            }
            if (id == "eyr") {
                int expirationYear = std::stoi(value);
                if (expirationYear >= 2020 && expirationYear <= 2030) {
                    eyr = true;
                }
            }
            if (id == "hgt") {
                int height;
                if (value.size() >= 3) {
                    std::string unit = value.substr(value.size() - 2);
                    if (unit == "cm") {
                        height = std::stoi(value.substr(0, value.size() - 2));
                        if (height >= 150 && height <= 193) {
                            hgt = true;
                        }
                    } else if (unit == "in") {
                        height = std::stoi(value.substr(0, value.size() - 2));
                        if (height >= 59 && height <= 76) {
                            hgt = true;
                        }
                    }
                }
            }
            if (id == "hcl") {
                std::regex hclRegex("#[0-9a-f]{6}");
                if (std::regex_match(value, hclRegex)) {
                    hcl = true;
                }
            }
            if (id == "ecl") {
                if (value == "amb" || value == "blu" || value == "brn" ||
                    value == "gry" || value == "grn" || value == "hzl" ||
                    value == "oth") {
                    ecl = true;
                }
            }
            if (id == "pid") {
                std::regex pidRegex("\\d{9}");
                if (std::regex_match(value, pidRegex)) {
                    pid = true;
                }
            }
        }
        if (byr && iyr && eyr && hgt && hcl && ecl && pid) {
            result++;
        }
    }

    return result;
}


int main() {
    std::string path = R"(/home/tibor/Desktop/advent-of-code/2020/Day04/Day04.txt)";
    std::cout << part1(path) << '\n';
    std::cout << part2(path) << '\n';
    return 0;
}