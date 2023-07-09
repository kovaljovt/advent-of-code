#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2016\Day01\Day01.txt)");
	std::string element;
	std::vector<std::string> data = {};

	while (std::getline(input, element, ',')) {
		size_t start = element.find_first_not_of(' ');
		size_t end = element.find_last_not_of(' ');
		element = element.substr(start, end - start + 1);
		data.push_back(element);
	}

	int result = 0;

	std::unordered_map<int, std::pair<int, int>> orientationMap = {
			{0, {0, 1}},
			{1, {1, 0}},
			{2, {0, -1}},
			{3, {-1, 0}}
	};

	int x = 0, y = 0;
	int orientation = 0;

	for (const auto& instruction : data) {
		if (instruction[0] == 'R') {
			orientation = (orientation + 1) % 4;
		}
		else if (instruction[0] == 'L') {
			orientation = (orientation - 1 + 4) % 4;
		}

		std::pair<int, int> move = orientationMap[orientation];
		int distance = std::stoi(instruction.substr(1));
		x += move.first * distance;
		y += move.second * distance;
	}

	result += std::abs(x) + std::abs(y);

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2016\Day01\Day01.txt)");
	std::string element;
	std::vector<std::string> data = {};

	while (std::getline(input, element, ',')) {
		size_t start = element.find_first_not_of(' ');
		size_t end = element.find_last_not_of(' ');
		element = element.substr(start, end - start + 1);
		data.push_back(element);
	}

	return 0;
}
