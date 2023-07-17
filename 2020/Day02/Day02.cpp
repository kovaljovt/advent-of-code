#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2020\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;

	for (const auto& str: data) {
		size_t colon = str.find(":");
		std::string policy = str.substr(0, colon);
		std::string password = str.substr(colon+1);

		size_t space = policy.find(' ');
		std::string range = policy.substr(0, space);
		std::string character = policy.substr(space+1);

		size_t dash = range.find('-');
		const int min = std::stoi(range.substr(0, dash));
		const int max = std::stoi(range.substr(dash+1));

		int counter = 0;

		for (const auto& ch: password) {
			if (ch == character[0])
				counter++;
		}

		if (min <= counter && counter <= max) { result++; }
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2020\Day02\Day02.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;

	for (const auto& str: data) {
		size_t colon = str.find(":");
		std::string policy = str.substr(0, colon);
		std::string password = str.substr(colon+1);

		size_t space = policy.find(' ');
		std::string range = policy.substr(0, space);
		std::string character = policy.substr(space+1);

		size_t dash = range.find('-');
		const int startIndex = std::stoi(range.substr(0, dash));
		const int endIndex = std::stoi(range.substr(dash+1));

		const size_t index1 = startIndex;
		const size_t index2 = endIndex;

		int counter = 0;

		if (password[index1] == character[0])
			counter++;

		if (password[index2] == character[0])
			counter++;

		if (counter == 1)
			result++;
	}

	return result;
}