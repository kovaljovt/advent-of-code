#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	std::map<std::string, int> posibilities = {};

	posibilities["A X"] = 4;
	posibilities["A Y"] = 8;
	posibilities["A Z"] = 3;
	posibilities["B X"] = 1;
	posibilities["B Y"] = 5;
	posibilities["B Z"] = 9;
	posibilities["C X"] = 7;
	posibilities["C Y"] = 2;
	posibilities["C Z"] = 6;

	int result = 0;

	for (const auto& posibility: data) {
		result += posibilities[posibility];
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	std::map<std::string, int> posibilities = {};

	posibilities["A X"] = 3;
	posibilities["A Y"] = 4;
	posibilities["A Z"] = 8;
	posibilities["B X"] = 1;
	posibilities["B Y"] = 5;
	posibilities["B Z"] = 9;
	posibilities["C X"] = 2;
	posibilities["C Y"] = 6;
	posibilities["C Z"] = 7;

	int result = 0;

	for (const auto& posibility: data) {
		result += posibilities[posibility];
	}

	return result;
}