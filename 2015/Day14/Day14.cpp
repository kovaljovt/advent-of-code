#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Player {
    std::string name = {};
    int speed = {};
    int time = {};
    int restTime = {};
};

int part1();
int part2();


int main()
{
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
}


int part1() {
    std::vector<Player> players = {
            Player{.name = "Dancer", .speed = 27, .time = 5, .restTime = 132},
            Player{.name = "Cupid", .speed = 22, .time = 2, .restTime = 41},
            Player{.name = "Rudolph", .speed = 11, .time = 5, .restTime = 48},
            Player{.name = "Donner", .speed = 28, .time = 5, .restTime = 134},
            Player{.name = "Dasher", .speed = 4, .time = 16, .restTime = 55},
            Player{.name = "Blitzen", .speed = 14, .time = 3, .restTime = 38},
            Player{.name = "Prancer", .speed = 3, .time = 21, .restTime = 40},
            Player{.name = "Comet", .speed = 18, .time = 6, .restTime = 103},
            Player{.name = "Vixen", .speed = 18, .time = 5, .restTime = 84},
    };

    std::vector<int> results = {};

    int wantedSeconds = 2503;

    for (const auto& player : players) {
        int time = wantedSeconds;
        int period = player.time + player.restTime;
        int periods = wantedSeconds / period;
        int result = player.speed * player.time * periods;
        time -= periods * period;
        time = std::min(time, player.time);
        result += time * player.speed;
        results.push_back(result);
    }

    return *std::max_element(results.begin(), results.end());
}


int part2() {
    return 0;
}