#ifndef ADVENT_OF_CODE_DAY09_H
#define ADVENT_OF_CODE_DAY09_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <filesystem>
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

	static int solve(Solution solution, const std::string &inputData);
};

#endif