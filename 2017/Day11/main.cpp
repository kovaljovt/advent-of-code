#include "Day11.h"

int main(int argc, char **argv) {
    std::string path = std::string(argv[argc-1]);
    if (!std::filesystem::exists(path)) {
        std::cout << "File does not exist!" << '\n';
        return -1;
    }

    std::string inputData;

    std::fstream input(path);
    std::vector<std::string> data;
    std::string line;
    std::getline(input, line);
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, ',')) {
        data.push_back(token);
    }

    /* SOLUTION */
    Day11 solver;
    std::cout << solver.solve(Solution::part1, data) << '\n';
    std::cout << solver.solve(Solution::part2, data) << '\n';

    return 0;
}