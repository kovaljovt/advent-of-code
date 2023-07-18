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
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2021\Day03\Day03.txt)");
	std::string line;
	std::vector<std::string> data;

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;

	int cols = data[0].size();

	std::string gamma;
	std::string epsilon;

	for (int i = 0; i < cols; i++) {
		int zeros = 0;
		int ones = 0;

		for (auto & j : data) {
			if (j[i] == '0')
				zeros++;
			else if (j[i] == '1')
				ones++;
		}

		if (zeros > ones) {
			gamma += "0";
			epsilon += "1";
		}
		else {
			gamma += "1";
			epsilon += "0";
		}
	}

	result += std::stoi(gamma, nullptr, 2) * std::stoi(epsilon, nullptr, 2);

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2021\Day03\Day03.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	return 0;
}