#include <iostream>
#include <string>
#include <fstream>

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2015\Day1\Day1.txt)");
	std::string output;
	std::getline(input, output);

	int result = 0;

	for (const auto& bracket: output) {
		if (bracket == '(') {
			result++;
		}
		else {
			result--;
		}
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2015\Day1\Day1.txt)");
	std::string output;
	std::getline(input, output);

	int result = 0;
	int floor = 0;
	int position = 0;

	while (floor != -1) {
		for (const auto& bracket: output) {
			if (bracket == '(') {
				floor++;
				position++;
			}
			else if (bracket == ')') {
				floor--;
				position++;
			}
			if (floor == -1) {
				break;
			}
		}
	}

	result = position;

	return result;
}