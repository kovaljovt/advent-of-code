#include <iostream>
#include <string>
#include <vector>
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
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2018\Day1\Day1.txt)");
	std::string line;
	std::vector<int> data = {};

	while (std::getline(input, line)) {
		data.push_back(std::stoi(line));
	}

	int result = 0;

	for (const auto& number: data) {
		result += number;
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2018\Day1\Day1.txt)");
	std::string line;
	std::vector<int> data = {};

	while (std::getline(input, line)) {
		data.push_back(std::stoi(line));
	}

	std::unordered_map<int, bool> seen = {};

	int result = 0;

	while (true) {
		for (const auto& number: data) {
			result += number;
			if (seen[result]) {
				return result;
			}
			seen[result] = true;
		}
	}
}