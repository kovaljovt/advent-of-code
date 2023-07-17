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
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day04\Day04.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;

	for (const auto& entry: data) {
		size_t commaPosition = entry.find(",");
		std::string first = entry.substr(0, commaPosition);
		std::string second = entry.substr(commaPosition+1);
		size_t dashPosition = first.find('-');
		int firstStart = std::stoi(first.substr(0, dashPosition));
		int firstEnd = std::stoi(first.substr(dashPosition+1));
		dashPosition = second.find('-');
		int secondStart = std::stoi(second.substr(0, dashPosition));
		int secondEnd = std::stoi(second.substr(dashPosition+1));

		if ((firstStart <= secondStart) && (firstEnd >= secondEnd))
			result++;
		else if ((secondStart <= firstStart) && (secondEnd >= firstEnd))
			result++;
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day04\Day04.txt)");
	std::string line;
	std::vector<std::string> data = {};

	while (std::getline(input, line)) {
		data.push_back(line);
	}

	int result = 0;

	for (const auto& entry: data) {
		size_t commaPosition = entry.find(",");
		std::string first = entry.substr(0, commaPosition);
		std::string second = entry.substr(commaPosition+1);
		size_t dashPosition = first.find('-');
		int firstStart = std::stoi(first.substr(0, dashPosition));
		int firstEnd = std::stoi(first.substr(dashPosition+1));
		dashPosition = second.find('-');
		int secondStart = std::stoi(second.substr(0, dashPosition));
		int secondEnd = std::stoi(second.substr(dashPosition+1));

		if ((firstStart >= secondStart && firstStart <= secondEnd) ||
		    (firstEnd >= secondStart && firstEnd <= secondEnd) ||
		    (secondStart >= firstStart && secondStart <= firstEnd) ||
		    (secondEnd >= firstStart && secondEnd <= firstEnd)) {
			result++;
		}
	}

	return result;
}