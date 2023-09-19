#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <map>
#include <vector>
#include <fstream>
#include <array>

struct Particle {
    std::array<int, 3> position;
    std::array<int, 3> velocity;
    std::array<int, 3> acceleration;
    bool destroyed = false;
};

std::vector<Particle> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<Particle> data;
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        char ignore;
        Particle particle {};
        particle.destroyed = false;
        iss >> ignore >> particle.position[0] >> ignore >> particle.position[1]
            >> ignore >> particle.position[2] >> ignore >> ignore
            >> ignore >> particle.velocity[0] >> ignore >> particle.velocity[1]
            >> ignore >> particle.velocity[2] >> ignore >> ignore
            >> ignore >> particle.acceleration[0] >> ignore >> particle.acceleration[1]
            >> ignore >> particle.acceleration[2] >> ignore;
        data.push_back(particle);
    }
    return data;
}


int part1(const std::string &path) {
    std::vector<Particle> data = parseInput(path);
    int result;

    int minDistance = INT_MAX;
    int closestParticle;
    int iterations = 1000;

    for (int i = 0; i < iterations; ++i) {
        for (auto &particle : data) {
            particle.velocity[0] += particle.acceleration[0];
            particle.velocity[1] += particle.acceleration[1];
            particle.velocity[2] += particle.acceleration[2];
            particle.position[0] += particle.velocity[0];
            particle.position[1] += particle.velocity[1];
            particle.position[2] += particle.velocity[2];
        }
    }

    for (int j = 0; j < data.size(); ++j) {
        int manhattanDistance = std::abs(data[j].position[0]) +
                                std::abs(data[j].position[1]) +
                                std::abs(data[j].position[2]);
        if (manhattanDistance < minDistance) {
            minDistance = manhattanDistance;
            closestParticle = j;
            result = closestParticle;
        }
    }

    return result;
}

int part2(const std::string &path) {
    std::vector<Particle> data = parseInput(path);
    int result = 0;

    int iterations = 1000;

    std::map<std::array<int, 3>, Particle*> collisions;
    for (int i = 0; i < iterations; ++i) {
        for (auto &particle: data) {
            if (!particle.destroyed) {
                particle.velocity[0] += particle.acceleration[0];
                particle.velocity[1] += particle.acceleration[1];
                particle.velocity[2] += particle.acceleration[2];
                particle.position[0] += particle.velocity[0];
                particle.position[1] += particle.velocity[1];
                particle.position[2] += particle.velocity[2];
                if (collisions.find(particle.position) != collisions.end()) {
                    particle.destroyed = true;
                    collisions[particle.position]->destroyed = true;
                } else {
                    collisions[particle.position] = &particle;
                }
            }
        }
    }

    for (auto &particle: data) {
        if (!particle.destroyed) {
            result++;
        }
    }

    return result;
}


int main() {
    std::string path = R"(/home/tibor/Desktop/advent-of-code/2017/Day20/Day20.txt)";
    std::cout << part1(path) << '\n';
    std::cout << part2(path) << '\n';
    return 0;
}