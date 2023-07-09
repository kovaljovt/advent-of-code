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
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2017\Day1\Day1.txt)");
	std::string output;
	std::getline(input, output);

	int result = 0;

	for (int i = 0; i < output.size()-1; i++) {
		if (output[i] == output[i+1]) {
			result += std::stoi(std::string(1, output[i]));
		}
	}

	if (output[0] == output[output.size()-1]) {
		result += std::stoi(std::string(1, output[0]));
	}

	return result;
}

int part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2017\Day1\Day1.txt)");
	std::string output;
	std::getline(input, output);

	int result = 0;

	int size = output.size();
	int half = output.size() / 2;

	for (int i = 0; i < output.size()-1; i++) {
		if (output[i] == output[(i+half) % size]) {
			result += std::stoi(std::string(1, output[i]));
		}
	}

	return result;
}