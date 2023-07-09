#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day1\Day1.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int maxCalories = 0;
	int elf = 0;

	for (const auto& calories: data) {
		if (calories.empty()) {
			elf = 0;
		}
		else {
			elf += std::stoi(calories);
		}
		if (elf > maxCalories) {
			maxCalories = elf;
		}
	}

	return maxCalories;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day1\Day1.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	std::vector<int> topThree = {};
	int elf = 0;
	int result = 0;

	for (const auto& calories: data) {
		if (calories.empty()) {
			elf = 0;
		}
		else {
			elf += std::stoi(calories);
			topThree.emplace_back(elf);
		}
	}

	std::sort(topThree.begin(), topThree.end());
	result = topThree[topThree.size()-1] + topThree[topThree.size()-2] + topThree[topThree.size()-3];

	return result;
}