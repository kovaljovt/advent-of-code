#include "Day12.h"

int main() {
	Day12 solver(Solution::part1);
	std::string filePath = R"(C:\Users\Acer\Desktop\advent-of-code\2022\Day12\Day12.txt)";

	std::cout << solver.solve(filePath) << '\n';
	solver.solution = Solution::part2;
	std::cout << solver.solve(filePath) << '\n';

	return 0;
}