#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <sstream>

std::vector<std::string> ReadAllLinesInFile(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    return lines;
}


std::vector<std::string> SplitString(const std::string& line, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t start = 0;
    size_t end = line.find(delimiter);
    while (end != std::string::npos) {
        tokens.push_back(line.substr(start, end - start));
        start = end + delimiter.length();
        end = line.find(delimiter, start);
    }
    tokens.push_back(line.substr(start, end));
    return tokens;
}


int main() {
    auto input = ReadAllLinesInFile("/home/tibor/Desktop/advent-of-code/2022/Day05/Day05.txt");

    auto blankIndex = -1;
    for(auto i = 0; i < input.size(); ++i) {
        if(input[i].size() == 0) {
            blankIndex = i;
            break;
        }
    }

    auto stacks = std::vector<std::stack<char>>{};
    const auto& stackLabels = input[blankIndex - 1];
    for(auto i = 0; i < stackLabels.size(); ++i) {
        if (stackLabels[i] == ' ') {
            continue;
        }
        auto currentStack = std::stack<char>{};
        for(auto lineIndex = blankIndex - 2; lineIndex >= 0; --lineIndex) {
            const auto& line = input[lineIndex];
            const auto& crate = line[i];
            if (crate == ' ') {
                break;
            }
            currentStack.push(crate);
        }
        stacks.emplace_back(currentStack);
    }

    for(auto i = blankIndex + 1; i < input.size(); ++i) {
        const auto& line = input[i];
        auto tokens = SplitString(line, " ");
        auto count = std::stoi(tokens[1]);
        auto from = std::stoi(tokens[3]) - 1;
        auto to = std::stoi(tokens[5]) - 1;

        auto crates = std::vector<char>{};
        while(count-- > 0) {
            auto crate = stacks[from].top();
            stacks[from].pop();
            crates.emplace_back(crate);
        }

        for (auto it = crates.rbegin(); it != crates.rend(); ++it) {
            auto crate = *it;
            stacks[to].push(crate);
        }
    }

    auto output = std::stringstream{};
    for(const auto& currentStack : stacks) {
        output << currentStack.top();
    }

    std::cout << output.str();
}