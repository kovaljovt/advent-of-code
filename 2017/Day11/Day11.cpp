#include "Day11.h"

Day11::Day11() {}


int Day11::solve(Solution solution, const std::vector<std::string> &data) {
    int result = 0;
    std::vector<int> coords = {0, 0};
    for (const auto &direction: data) {
        if (direction == "n") { coords[0]++; }
        if (direction == "ne") { coords[1]++; }
        if (direction == "se") { coords[0]--, coords[1]++; }
        if (direction == "s") { coords[0]--; }
        if (direction == "sw") { coords[1]--; }
        if (direction == "nw") { coords[0]++, coords[1]--; }
        int x = coords[0];
        int z = coords[1];
        int y = -x - z;
        int distance = std::max(std::max(std::abs(x), std::abs(y)), std::abs(z));
        if (solution == Solution::part1) {
            result = std::max(distance, 0);
        } else {
            result = std::max(distance, result);
        }
    }
    return result;
}