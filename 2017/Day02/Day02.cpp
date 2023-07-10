#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2017\Day02\Day02.txt)");
	std::string line;
	std::vector<std::vector<int>> data = {};

	while (std::getline(input, line)) {
		std::vector<int> row;
		int value;
		std::istringstream iss(line);
		while (iss >> value) {
			row.push_back(value);
		}
		data.push_back(row);
	}

	int result = 0;
	std::vector<int> answers = {};

	for (const auto& row : data) {
		answers.push_back(*std::max_element(row.begin(), row.end()) - *std::min_element(row.begin(), row.end()));
	}

	for (const auto& number: answers) {
		result += number;
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2017\Day02\Day02.txt)");
	std::string line;
	std::vector<std::vector<int>> data = {};

	while (std::getline(input, line)) {
		std::vector<int> row;
		int value;
		std::istringstream iss(line);
		while (iss >> value) {
			row.push_back(value);
		}
		data.push_back(row);
	}

	int result = 0;
	std::vector<int> answers = {};

	for (const auto& innerVector: data) {
		for (int i = 0; i < innerVector.size(); i++) {
			for (int j = i + 1; j < innerVector.size(); j++) {
				if (innerVector[i] % innerVector[j] == 0) {
					answers.push_back(innerVector[i] / innerVector[j]);
				}
				else if (innerVector[j] % innerVector[i] == 0) {
					answers.push_back(innerVector[j] / innerVector[i]);
				}
			}
		}
	}

	for (const auto& number: answers) {
		result += number;
	}

	return result;
}