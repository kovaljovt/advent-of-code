#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2021\Day01\Day01.txt)");
	std::string line;
	std::vector<int> data = {};

	while (std::getline(input, line)) {
		data.push_back(std::stoi(line));
	}

	int result = 0;

	for (int i = 0; i < data.size(); i++) {
		if (data[i] > data[i-1]) {
			result++;
		}
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2021\Day01\Day01.txt)");
	std::string line;
	std::vector<int> data = {};

	while (std::getline(input, line)) {
		data.push_back(std::stoi(line));
	}

	int result = 0;

	for (int i = 3; i < data.size(); i++) {
		if (data[i] > data[i-3]) {
			result++;
		}
	}

	return result;
}