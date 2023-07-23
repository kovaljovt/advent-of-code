#include <iostream>
#include <string>
#include <fstream>
#include <set>

int part1();

int part2();

std::pair<int, int> update(std::pair<int, int> position, char direction);

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

std::pair<int, int> update(std::pair<int, int> position, char direction) {
	if (direction == '^') {
		return {position.first, position.second + 1};
	} else if (direction == '<') {
		return {position.first - 1, position.second};
	} else if (direction == '>') {
		return {position.first + 1, position.second};
	} else if (direction == 'v') {
		return {position.first, position.second - 1};
	}
	return position;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2015\Day03\Day03.txt)");
	std::string output;
	std::getline(input, output);

	int result;

	std::set<std::pair<int, int>> visited = {};
	visited.insert({0 ,0});
	std::pair<int, int> position = {0, 0};

	for (const auto& direction: output) {
		position = update(position, direction);
		visited.insert(position);
	}

	result = visited.size();

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2015\Day03\Day03.txt)");
	std::string output;
	std::getline(input, output);

	int result;

	std::set<std::pair<int, int>> visited = {};
	visited.insert({0 ,0});
	std::pair<int, int> santa = {0, 0};
	std::pair<int, int> roboSanta = {0, 0};

	for (size_t i = 0; i < output.size(); i++) {
		char direction = output[i];
		if (i % 2 == 0) {
			roboSanta = update(roboSanta, direction);
			visited.insert(roboSanta);
		} else {
			santa = update(santa, direction);
			visited.insert(santa);
		}
	}

	result = visited.size();

	return result;
}