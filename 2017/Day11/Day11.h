#ifndef ADVENT_OF_CODE_DAY11_H
#define ADVENT_OF_CODE_DAY11_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <filesystem>
#include <fstream>

enum struct Solution : int {
    part1,
    part2
};

class Day11 {
public:
    Day11();
    int solve(Solution solution, const std::vector<std::string> &path);
};

#endif
