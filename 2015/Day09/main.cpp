#include "Day09.h"

int main() {
	Day09 solver;
	int part1 = solver.solve(Solution::part1);
	int part2 = solver.solve(Solution::part2);
	std::cout << part1 << '\n';
	std::cout << part2 << '\n';
	return 0;
}