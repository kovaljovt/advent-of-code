#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

struct Claim {
    int id;
    int x;
    int y;
    int width;
    int height;
};


std::vector<Claim> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<Claim> data;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        char ignore;
        Claim claim {};
        iss >> ignore >> claim.id >> ignore >> claim.x >> ignore
            >> claim.y >> ignore >> claim.width >> ignore >> claim.height;
        data.push_back(claim);
    }
    return data;
}


int part1(const std::string &path) {
    std::vector<Claim> data = parseInput(path);
    std::vector<std::vector<int>> plot = {};
    int result = 0;

    for(int i = 0; i < 1000; i++) {
        plot.emplace_back();
        for(int j = 0; j < 1000; j++) {
            plot.back().emplace_back(0);
        }
    }

    for(auto& claim : data) {
        for(int x = 0; x < claim.width; x++) {
            for(int y = 0; y < claim.height; y++) {
                plot[claim.y+y][claim.x+x]++;
            }
        }
    }

    for(int x = 0; x < 1000; x++) {
        for(int y = 0; y < 1000; y++) {
            result += static_cast<int>(plot[y][x] >= 2);
        }
    }

    return result;
}


int part2(const std::string &path) {
    std::vector<Claim> data = parseInput(path);
    std::vector<std::vector<int>> plot = {};
    int result = 0;

    for(int i = 0; i < 1000; i++) {
        plot.emplace_back();
        for(int j = 0; j < 1000; j++) {
            plot.back().emplace_back(0);
        }
    }

    for(auto& claim : data) {
        for(int x = 0; x < claim.width; x++) {
            for(int y = 0; y < claim.height; y++) {
                plot[claim.y+y][claim.x+x]++;
            }
        }
    }

    for (int i = 0; i < data.size(); i++) {
        bool onlyOne = true;
        for (int x = 0; x < data[i].width; x++) {
            for (int y = 0; y < data[i].height; y++) {
                onlyOne = plot[data[i].y + y][data[i].x + x] == 1;
                if (!onlyOne) break;
            }
            if (!onlyOne) break;
        }
        if (onlyOne) {
            result = data[i].id;
            break;
        }
    }

    return result;
}


int main() {
    std::string path = R"(/home/tibor/Desktop/advent-of-code/2018/Day03/Day03.txt)";
    std::cout << part1(path) << '\n';
    std::cout << part2(path) << '\n';
    return 0;
}