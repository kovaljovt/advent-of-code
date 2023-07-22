#ifndef ADVENT_OF_CODE_DAY12_H
#define ADVENT_OF_CODE_DAY12_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
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
public:
	Solution solution = {};

	Day12(Solution sol);

	void readInputFromFile(const std::string &filePath, std::vector<std::string> &data);

	int solve(const std::string &filePath);

private:
	bool inBounds(const Coords &point, const std::vector<std::string> &data);
};

#endif
