#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <unordered_map>

int part1();

std::string part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2018\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int twoLetter = 0;
	int threeLetter = 0;

	for (const auto &str: data) {
		std::unordered_map<char, int> characterCount;
		for (const auto &character: str) {
			characterCount[character]++;
		}
		bool foundTwo = false;
		bool foundThree = false;
		for (const auto &pair: characterCount) {
			if (pair.second == 2 && !foundTwo) {
				twoLetter++;
				foundTwo = true;
			} else if (pair.second == 3 && !foundThree) {
				threeLetter++;
				foundThree = true;
			}
		}
	}

	int result = twoLetter * threeLetter;

	return result;
}

std::string part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2018\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	for (const auto& x : data) {
		for (const auto& y : data) {
			int diff = 0;
			std::string ans;
			for (size_t i = 0; i < x.size(); i++) {
				if (x[i] != y[i]) {
					diff++;
				}
				if (diff > 1) {
					break;
				}
				if (x[i] == y[i]) {
					ans += x[i];
				}
			}
			if (diff == 1) {
				return ans;
			}
		}
	}
}