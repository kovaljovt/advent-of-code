#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2015\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data;

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;

	for (const auto &num: data) {
		std::istringstream iss(num);
		std::string token;
		std::vector<int> dimensions;

		while (std::getline(iss, token, 'x')) {
			dimensions.push_back(std::stoi(token));
		}

		int a = dimensions[0];
		int b = dimensions[1];
		int c = dimensions[2];

		int surface = 2 * (a * b + b * c + a * c);
		int slack = std::min({a * b, a * c, b * c});
		int paper = surface + slack;

		result += paper;
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2015\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data;

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;

	for (const auto &num: data) {
		std::istringstream iss(num);
		std::string token;
		std::vector<int> dimensions;

		while (std::getline(iss, token, 'x')) {
			dimensions.push_back(std::stoi(token));
		}

		int a = dimensions[0];
		int b = dimensions[1];
		int c = dimensions[2];

		int volume = a*b*c;
		int ribbon = 2 * (a + b + c - *std::max_element(dimensions.begin(), dimensions.end()));

		result += volume + ribbon;
	}

	return result;
}