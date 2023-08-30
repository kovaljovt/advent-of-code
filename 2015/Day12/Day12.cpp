#include <iostream>
#include <cassert>
#include <regex>
#include <string>
#include <fstream>

int part1();
int part2();
int parseNumbers(std::string const &s);
int parseNumbers2(std::string const &s);
int doParse(std::string const &s, std::string::size_type &pos);


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}


int part1() {
    std::fstream input("/home/tibor/Desktop/advent-of-code/2015/Day12/Day12.txt");
    std::string line;
    int acc = 0;
    while (std::getline(input, line)) {
        acc += parseNumbers(line);
    }
    return acc;
}


int part2() {
    std::fstream input("/home/tibor/Desktop/advent-of-code/2015/Day12/Day12.txt");
    std::string line;
    int acc = 0;
    while (std::getline(input, line)) {
        acc += parseNumbers2(line);
    }
    return acc;
}


int parseNumbers(std::string const &s) {
    static const std::regex re("-?\\d+");
    std::string left = s;
    std::smatch m;
    int acc = 0;
    while (std::regex_search(left, m, re)) {
        acc += std::stoi(m.str(0));
        left = m.suffix();
    }
    return acc;
}


int parseNumbers2(std::string const &s)
{
    std::string::size_type pos = 0;
    int result = doParse(s, pos);
    assert(pos == s.size());
    return result;
}


int doParse(std::string const &s, std::string::size_type &pos) {
    int result = 0;
    bool ignore = false;
    while (pos < s.size()) {
        if (s[pos] == '{') {
            ++pos;
            result += doParse(s, pos);
        }
        else if (s[pos] == '[') {
            ++pos;
            result += doParse(s, pos);
        }
        else if (s[pos] == '}') {
            ++pos;
            return ignore ? 0 : result;
        }
        else if (s[pos] == ']') {
            ++pos;
            return result;
        }
        else if (s[pos] == '"') {
            ++pos;
            auto e = s.find('"', pos);
            assert(e != std::string::npos);
            std::string v = s.substr(pos, e - pos);
            if (v == "red") {
                ignore = true;
            }
            pos = e + 1;
        }
        else if (std::isdigit(s[pos]) || s[pos] == '-') {
            std::size_t len = 0;
            result += std::stoi(s.substr(pos), &len);
            pos += len;
        }
        else {
            assert(s[pos] == ',' || s[pos] == ':');
            ++pos;
        }
    }
    return result;
}