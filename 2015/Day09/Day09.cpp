#include "Day09.h"

Day09::Day09() = default;

std::vector<Route> Day09::readInputFromFile(const std::string &filePath) {
	std::fstream input(filePath);
	std::string line;
	std::vector<Route> routes;
	while (std::getline(input, line)) {
		std::string from, to;
		int distance;
		size_t equalPos = line.find('=');
		if (equalPos != std::string::npos) {
			size_t toPos = line.find("to");
			from = line.substr(0, toPos - 1);
			to = line.substr(toPos + 3, equalPos - toPos - 4);
			distance = std::stoi(line.substr(equalPos + 2));
			routes.push_back({from, to, distance});
		}
	}
	return routes;
}

int Day09::solve(Solution solution, const std::string &path) {
	std::vector<Route> routes = readInputFromFile(path);
	std::set<std::string> uniqueStations;

	for (const auto &route: routes) {
		uniqueStations.emplace(route.from);
		uniqueStations.emplace(route.to);
	}

	std::vector<int> distances;
	std::stack<Result> stateStack;

	for (const auto &station: uniqueStations) {
		std::set<std::string> stationsToVisit = uniqueStations;
		stationsToVisit.erase(station);
		stateStack.push(Result{
				.distance = 0,
				.from = station,
				.notVisited = stationsToVisit
		});
	}

	while (!stateStack.empty()) {
		Result currentResult = stateStack.top();
		stateStack.pop();

		if (currentResult.notVisited.empty()) {
			distances.push_back(currentResult.distance);
		}

		for (const auto &station: currentResult.notVisited) {
			Result newResult = currentResult;
			newResult.notVisited.erase(station);

			for (const auto &route: routes) {
				if ((currentResult.from == route.from || currentResult.from == route.to) &&
				    (station == route.from || station == route.to)) {
					newResult.distance += route.distance;
					newResult.from = station;
					stateStack.push(newResult);
				}
			}
		}
	}

	if (solution == Solution::part1) {
		return *std::min_element(distances.begin(), distances.end());
	} else {
		return *std::max_element(distances.begin(), distances.end());
	}
}
