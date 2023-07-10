#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2019\Day01\Day01.txt)");
	std::string line;
	std::vector<int> data = {};

	while (std::getline(input, line)) {
		data.push_back(std::stoi(line));
	}

	int result = 0;

	for (const auto& number: data) {
		result += std::ceil((number / 3) - 2);
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2019\Day01\Day01.txt)");
	std::string line;
	std::vector<int> data = {};

	while (std::getline(input, line)) {
		data.push_back(std::stoi(line));
	}

	int result = 0;

	for (const auto& number: data) {
		int currentNumber = number;
		while (true) {
			int fuel = std::ceil((currentNumber / 3) - 2);
			if (fuel <= 0) { break; }
			result += fuel;
			currentNumber = fuel;
		}
	}

	return result;
}