#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day03\Day03.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;

	std::unordered_map<char, int> letterPriority = {};

	int priority = 1;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for(const auto& character : alphabet) {
		letterPriority[character] = priority;
		priority++;
	}

	for(const auto& rucksack : data) {
		auto half = rucksack.length() / 2;
		std::string left = rucksack.substr(0, half);
		std::string right = rucksack.substr(half);
		for(const auto& character : alphabet) {
			if(left.find(character) != std::string::npos
				&& right.find(character) != std::string::npos) {
				result += letterPriority[character];
			}
		}
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day03\Day03.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;
	std::unordered_map<char, int> letterPriority = {};
	std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	int j = 3;
	for (int i = 0; i < data.size(); i += 3) {
		std::vector<std::string> rucksacks = {};
		for (int k = i; k < j; k++) {
			if (k < data.size()) {
				rucksacks.push_back(data[k]);
			}
		}
		j += 3;

		for (const auto& character: alphabet) {
			bool foundInAllRucksacks = true;
			for (const auto& rucksack: rucksacks) {
				if (rucksack.find(character) == std::string::npos) {
					foundInAllRucksacks = false;
					break;
				}
			}

			if (foundInAllRucksacks) {
				result += letterPriority[character];
			}
		}
	}

	return result;
}