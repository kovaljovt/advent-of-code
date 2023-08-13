#include <iostream>
#include <string>
#include <unordered_set>
#include <fstream>

std::string readInputFromFile(const std::string &filePath);

int part1();

int part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';
	return 0;
}

std::string readInputFromFile(const std::string &filePath) {
	std::fstream input(filePath);
	std::string output;
	std::getline(input, output);
	return output;
}

int part1() {
	std::string data = readInputFromFile(R"(C:\Users\Acer\Desktop\drawer\programming\cpp\advent-of-code\2022\Day06\Day06.txt)");
	for (int i = 4; i < data.size(); i++) {
		std::unordered_set<char> set;
		for(int j = i - 4; j < i; j++) {
			set.insert(data[j]);
		}
		if(set.size() == 4) {
			return i;
		}
	}
	return 0;
}

int part2() {
	std::string data = readInputFromFile(R"(C:\Users\Acer\Desktop\drawer\programming\cpp\advent-of-code\2022\Day06\Day06.txt)");
	for (int i = 14; i < data.size(); i++) {
		std::unordered_set<char> set;
		for (int j = i - 14; j < i; j++) {
			set.insert(data[j]);
		}
		if (set.size() == 14) {
			return i;
		}
	}
	return 0;
}