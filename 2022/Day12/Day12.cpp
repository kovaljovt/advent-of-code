#include "Day12.h"

Day12::Day12() {}

std::vector<std::string> Day12::readInputFromFile(const std::string &filePath) {
	std::fstream input(filePath);
	std::vector<std::string> data = {};
	std::string line;
	while (std::getline(input, line)) {
		data.push_back(line);
	}
	return data;
}

bool Day12::inBounds(const Coords &point, const std::vector<std::string> &data) {
	return point.x >= 0 && point.y >= 0 && point.x < data.size() && point.y < data[0].size();
}

int Day12::solve(Solution solution) {
	std::vector<std::string> data = readInputFromFile(R"(C:\Users\Acer\Desktop\adventp\Day12.txt)");

	Coords start {};
	Coords end {};
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			if (data[i][j] == 'S') {
				data[i][j] = 'a';
				if (solution == Solution::part1) {
					start.x = i;
					start.y = j;
					start.steps = 0;
				}
			}
			if (data[i][j] == 'E') {
				data[i][j] = 'z';
				end.x = i;
				end.y = j;
				end.steps = 0;
			}
		}
	}

	std::vector<Coords> directions = {
			Coords{1, 0, 0},
			Coords{0, 1, 0},
			Coords{-1, 0, 0},
			Coords{0, -1, 0}
	};

	std::vector<std::vector<bool>> visited(data.size(), std::vector<bool>(data[0].size(), false));

	std::queue<Coords> coords;
	if (solution == Solution::part1) {
		coords.push(start);
	}
	else {
		coords.push(end);
	}

	while (!coords.empty()) {
		Coords currentCoord = coords.front();
		coords.pop();

		if (visited[currentCoord.x][currentCoord.y]) { continue; }

		visited[currentCoord.x][currentCoord.y] = true;

		if (solution == Solution::part1) {
			if (currentCoord.x == end.x && currentCoord.y == end.y) { return currentCoord.steps; }
		} else {
			if (data[currentCoord.x][currentCoord.y] == 'a') {
				return currentCoord.steps;
			}
		}

		for (const Coords &dir: directions) {
			const Coords newPoint = Coords{
					.x = currentCoord.x + dir.x,
					.y = currentCoord.y + dir.y,
					.steps = currentCoord.steps + 1
			};

			if (!inBounds(newPoint, data)) { continue; }
			if (visited[newPoint.x][newPoint.y]) { continue; }
			if (solution == Solution::part1) {
				if ((data[currentCoord.x][currentCoord.y] + 1) < (data[newPoint.x][newPoint.y])) { continue; }
			} else {
				if ((data[currentCoord.x][currentCoord.y]) > (data[newPoint.x][newPoint.y]) + 1) { continue; }
			}

			coords.push(newPoint);
		}
	}

	return 0;
}


