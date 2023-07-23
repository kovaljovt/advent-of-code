#include <iostream>
#include <string>
#include <vector>
#include <fstream>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2016\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	return 0;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2016\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	return 0;
}