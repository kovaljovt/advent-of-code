#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <fstream>

enum Direction {
    North,
    East,
    South,
    West
};


struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};


std::vector<std::string> parseInput(const std::string &filePath) {
    std::ifstream input(filePath);
    std::string line;
    std::vector<std::string> data;
    while (std::getline(input, line)) {
        std::istringstream ss(line);
        std::string direction;
        while (std::getline(ss, direction, ',')) {
            data.push_back(direction);
        }
    }
    return data;
}


int part1(const std::string &path) {
    std::vector<std::string> data = parseInput(path);
    Direction direction = Direction::North;
    int x = 0;
    int y = 0;
    int result;

    for(auto &step : data) {
        if(direction == Direction::North) {
            if(step[0] == 'R') {
                direction = Direction::East;
            } else {
                direction = Direction::West;
            }
        } else if(direction == Direction::East) {
            if(step[0] == 'R') {
                direction = Direction::South;
            } else {
                direction = Direction::North;
            }
        } else if(direction == Direction::South) {
            if(step[0] == 'R') {
                direction = Direction::West;
            } else {
                direction = Direction::East;
            }
        } else {
            if (step[0] == 'R') {
                direction = Direction::North;
            }
            else {
                direction = Direction::South;
            }
        }

        if(direction == Direction::North) {
            y += std::stoi(step.substr(1, step.size() - 1));
        } else if(direction == Direction::South) {
            y -= std::stoi(step.substr(1, step.size() - 1));
        } else if(direction == Direction::East) {
            x += std::stoi(step.substr(1, step.size() - 1));
        } else {
            x -= std::stoi(step.substr(1, step.size() - 1));
        }
    }

    result = std::abs(x) + std::abs(y);
    return result;
}


int part2(const std::string &path) {
    std::vector<std::string> data = parseInput(path);
    Direction direction = Direction::North;
    int x = 0;
    int y = 0;
    int result;

    std::unordered_map<std::pair<int, int>, bool, pair_hash> visited;

    for (auto& step : data) {
        if (direction == Direction::North) {
            if (step[0] == 'R') {
                direction = Direction::East;
            }
            else {
                direction = Direction::West;
            }
        }
        else if (direction == Direction::East) {
            if (step[0] == 'R') {
                direction = Direction::South;
            }
            else {
                direction = Direction::North;
            }
        }
        else if (direction == Direction::South) {
            if (step[0] == 'R') {
                direction = Direction::West;
            }
            else {
                direction = Direction::East;
            }
        }
        else {
            if (step[0] == 'R') {
                direction = Direction::North;
            }
            else {
                direction = Direction::South;
            }
        }

        int distance = std::stoi(step.substr(1, step.size() - 1));
        for (int i = 0; i < distance; i++) {
            if (direction == Direction::North) {y++;}
            else if (direction == Direction::South) {y--;}
            else if (direction == Direction::East) {x++;}
            else {x--;}

            std::pair<int, int> position(x, y);
            if (visited.find(position) != visited.end()) {
                result = std::abs(x) + std::abs(y);
                return result;
            }
            else {
                visited[position] = true;
            }
        }
    }

    result = std::abs(x) + std::abs(y);
    return result;
}


int main() {
    std::string path = R"(/home/tibor/Desktop/advent-of-code/2016/Day01/Day01.txt)";
    std::cout << part1(path) << '\n';
    std::cout << part2(path) << '\n';
    return 0;
}