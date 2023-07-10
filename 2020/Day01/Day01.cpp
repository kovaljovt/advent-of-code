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
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2020\Day01\Day01.txt)");
	std::string line;
	std::vector<int> data = {};

	while (std::getline(input, line)) {
		data.push_back(std::stoi(line));
	}

	int num1, num2;

	for (int i = 0; i < data.size(); i++) {
		for (int j = i+1; j < data.size(); j++) {
			if ((data[i] + data[j]) == 2020) {
				num1 = data[i];
				num2 = data[j];
			}
		}
	}

	return num1 * num2;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2020\Day01\Day01.txt)");
	std::string line;
	std::vector<int> data = {};

	while (std::getline(input, line)) {
		data.push_back(std::stoi(line));
	}

	int num1, num2, num3;

	for (int i = 0; i < data.size(); i++) {
		for (int j = i + 1; j < data.size(); j++) {
			for (int k = j + 1; k < data.size(); k++) {
				if ((data[i] + data[j] + data[k]) == 2020) {
					num1 = data[i];
					num2 = data[j];
					num3 = data[k];
				}
			}
		}
	}

	return num1 * num2 * num3;
}