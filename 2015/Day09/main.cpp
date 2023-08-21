#include "Day09.h"

int main(int argc, char** argv) {
    // reading link
    std::string path = std::string(argv[argc-1]);

    // checking if file exists
    if (!std::filesystem::exists(path)) {
        std::cout << "File not opened!" << '\n';
        return -1;
    }

	Day09 solver;
    std::string inputData;

    if (std::filesystem::is_regular_file(path)) {
        std::ifstream input(path);
        std::ostringstream buffer;
        buffer << input.rdbuf();
        inputData = buffer.str();
    } else {
        std::cerr << "Invalid file!" << '\n';
        return 1;
    }

    // calling the solve method
	int part1 = solver.solve(Solution::part1, path);
	int part2 = solver.solve(Solution::part2, path);
	std::cout << part1 << '\n';
	std::cout << part2 << '\n';

	return 0;
}