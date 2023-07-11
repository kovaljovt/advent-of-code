#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2021\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int depth = 0;
	int horizontalPosition = 0;
	int result = 0;

	for (const auto & instruction : data) {
		std::istringstream in(instruction);
		std::vector<std::string> parts = {};
		std::string part;
		while (in >> part) {
			parts.push_back(part);
		}

		if (parts[0] == "forward") {
			horizontalPosition += std::stoi(parts[1]);
		}
		else if (parts[0] == "up") {
			depth -= std::stoi(parts[1]);
		}
		else if (parts[0] == "down") {
			depth += std::stoi(parts[1]);
		}
	}

	result += horizontalPosition * depth;

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2021\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int aim = 0;
	int depth = 0;
	int horizontalPosition = 0;
	int result = 0;

	for (const auto & instruction : data) {
		std::istringstream in(instruction);
		std::vector<std::string> parts = {};
		std::string part;
		while (in >> part) {
			parts.push_back(part);
		}

		if (parts[0] == "forward") {
			horizontalPosition += std::stoi(parts[1]);
			depth += aim * std::stoi(parts[1]);
		}
		else if (parts[0] == "up") {
			aim -= std::stoi(parts[1]);
		}
		else if (parts[0] == "down") {
			aim += std::stoi(parts[1]);
		}
	}

	result += horizontalPosition * depth;

	return result;
}