#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

int part1();

std::string part2();

int main() {
	std::cout << part1() << '\n';
	std::cout << part2() << '\n';

	return 0;
}

int part1() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2019\Day02\Day02.txt)");
	std::string output;
	std::getline(input, output);
	std::stringstream ss(output);
	std::string num;

	std::vector<int> data = {};

	while (std::getline(ss, num, ',')) {
		data.push_back(std::stoi(num));
	}

	int result = 0;

	int ip = 0;
	data[1] = 12;
	data[2] = 2;

	while (true) {
		int opcode = data[ip];
		int i1 = data[ip+1];
		int i2 = data[ip+2];
		int i3 = data[ip+3];

		if (opcode == 1) {
			data[i3] = data[i1] + data[i2];
		} else if (opcode == 2) {
			data[i3] = data[i1] * data[i2];
		} else {
			break;
		}

		ip += 4;
	}

	result += data[0];

	return result;
}

std::string part2() {
	std::fstream input(R"(C:\Users\Acer\Desktop\advent-of-code\2019\Day02\Day02.txt)");
	std::string output;
	std::getline(input, output);
	std::stringstream ss(output);
	std::string num;

	std::vector<int> data = {};

	while (std::getline(ss, num, ',')) {
		data.push_back(std::stoi(num));
	}

	std::string result;

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			std::vector<int> helpData = {};

			for (const auto& number: data) {
				helpData.push_back(number);
			}

			helpData[1] = i;
			helpData[2] = j;
			int ip = 0;

			while (true) {
				int opcode = data[ip];
				int i1 = helpData[ip+1];
				int i2 = helpData[ip+2];
				int i3 = helpData[ip+3];

				if (opcode == 1) {
					helpData[i3] = helpData[i1] + helpData[i2];
				} else if (opcode == 2) {
					helpData[i3] = helpData[i1] * helpData[i2];
				} else {
					break;
				}

				ip += 4;
			}

			if (helpData[0] == 19690720) {
				result += std::to_string(i);
				result += std::to_string(j);
			}
		}
	}

	return result;
}