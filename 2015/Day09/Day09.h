#ifndef ADVENT_OF_CODE_DAY09_H
#define ADVENT_OF_CODE_DAY09_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <fstream>

enum struct Solution : int {
	part1,
	part2
};

struct Route {
	std::string from;
	std::string to;
	int distance;
};

struct Result {
	int distance;
	std::string from;
	std::set<std::string> notVisited;
};

class Day09 {
public:
	Day09();

	std::vector<Route> readInputFromFile(const std::string &filePath);

	int solve(Solution solution);
};

#endif