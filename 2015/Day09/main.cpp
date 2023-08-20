#include "Day09.h"

int main(int argc, char** argv) {
    std::string path = std::string(argv[argc-1]);
    if (!std::filesystem::exists(path)) {
        std::cout << "File not opened!" << '\n';
        return -1;
    }
	Day09 solver;
	int part1 = solver.solve(Solution::part1, path);
	int part2 = solver.solve(Solution::part2, path);
	std::cout << part1 << '\n';
	std::cout << part2 << '\n';
	return 0;
}