#ifndef ADVENTP_DAY12_H
#define ADVENTP_DAY12_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <filesystem>
#include <fstream>

enum struct Solution : int {
    part1,
    part2
};

struct Coords {
    int x;
    int y;
    int steps;
};

class Day12 {
private:
    bool inBounds(const Coords &point, const std::vector<std::string> &data);

public:
    Day12();

    int solve(Solution solution, const std::string &path);
};

#endif
