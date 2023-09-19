#include <algorithm>
#include <iostream>
#include <map>

int part1() {
    int x = 0, y = 0;
    std::map<int, std::map<int, int>> all;
    int step = 1;
    int c = 1;
    all[0][0] = 1;

    int target = 312051;

    while (true) {
        for (int i = 0; i < step; ++i) {
            ++c;
            ++x;
            if (c == target) {
                return std::abs(x) + std::abs(y);
            }
        }
        for (int i = 0; i < step; ++i) {
            ++c;
            ++y;
            if (c == target) {
                return std::abs(x) + std::abs(y);
            }
        }
        ++step;
        for (int i = 0; i < step; ++i) {
            ++c;
            --x;
            if (c == target) {
                return std::abs(x) + std::abs(y);
            }
        }
        for (int i = 0; i < step; ++i) {
            ++c;
            --y;
            if (c == target) {
                return std::abs(x) + std::abs(y);
            }
        }
        ++step;
    }
}


int part2() {
    int x = 0, y = 0;
    std::map<int, std::map<int, int>> all;
    int step = 1;
    int c = 1;
    all[0][0] = 1;

    int target = 312051;

    auto check = [&](const int value) {
        int r = 0;
        auto tryadd = [&](const int nx, const int ny) {
            if (all.find(nx) != all.end() && all[nx].find(ny) != all[nx].end()) {
                r += all[nx][ny];
            }
        };
        tryadd(x - 1, y - 1);
        tryadd(x + 1, y - 1);
        tryadd(x - 1, y + 1);
        tryadd(x + 1, y + 1);
        tryadd(x + 1, y);
        tryadd(x - 1, y);
        tryadd(x, y + 1);
        tryadd(x, y - 1);
        all[x][y] = r;
        if(r > target) {
            return r;
        }
        return 0;
    };

    while (true) {
        for (int i = 0; i < step; ++i) {
            ++c;
            ++x;
            int checking = check(c);
            if (checking > target) {
                return checking;
            }
        }
        for (int i = 0; i < step; ++i) {
            ++c;
            ++y;
            int checking = check(c);
            if (checking > target) {
                return checking;
            }
        }
        ++step;
        for (int i = 0; i < step; ++i) {
            ++c;
            --x;
            int checking = check(c);
            if (checking > target) {
                return checking;
            }
        }
        for (int i = 0; i < step; ++i) {
            ++c;
            --y;
            int checking = check(c);
            if (checking > target) {
                return checking;
            }
        }
        ++step;
    }
}


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}

