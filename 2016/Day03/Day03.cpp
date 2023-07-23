#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int part1();

int part2();

bool isValidTriangle(int, int, int);

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2016\Day03\Day03.txt)");
	std::string line;
	std::vector<std::vector<int>> data = {};

	while (std::getline(input, line)) {
		std::vector<int> row;
		std::istringstream iss(line);

		int num;
		while (iss >> num) {
			row.push_back(num);
		}

		data.push_back(row);
	}

	int result = 0;

	for (const auto& i : data) {
		if ((i[0] + i[1] > i[2]) &&
		    (i[0] + i[2] > i[1]) &&
		    (i[1] + i[2] > i[0])) {
			result++;
		}
	}

	return result;
}

bool isValidTriangle(int a, int b, int c) {
	return (a + b > c) && (a + c > b) && (b + c > a);
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2016\Day03\Day03.txt)");
	std::string line;
	std::vector<std::vector<int>> data = {};

	while (std::getline(input, line)) {
		std::istringstream iss(line);
		std::vector<int> row = {};
		int num;
		while (iss >> num) {
			row.push_back(num);
		}
		data.push_back(row);
	}

	int result = 0;

	for (size_t i = 0; i < data.size(); i += 3) {
		for (int j = 0; j < 3; ++j) {
			if (isValidTriangle(data[i][j], data[i + 1][j], data[i + 2][j])) {
				result++;
			}
		}
	}

	return result;
}
