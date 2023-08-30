#include <iostream>
#include <string>

int part1();
int part2();


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}


int part1() {
    std::string input = "1113222113";

    for(int i = 0; i < 40; i++) {
        input = [&](const std::string& str) -> std::string {
            std::string output = "";
            for(int i = 0; i < str.length();) {
                char ch = str[i];
                int num = 0;
                while(ch == str[i]) {
                    num++;
                    i++;
                }
                output += std::to_string(num) + ch;
            }
            return output;
        }(input);
    }

    return input.length();
}


int part2() {
    std::string input = "1113222113";

    for(int i = 0; i < 50; i++) {
        input = [&](const std::string& str) -> std::string {
            std::string output = "";
            for(int i = 0; i < str.length();) {
                char ch = str[i];
                int num = 0;
                while(ch == str[i]) {
                    num++;
                    i++;
                }
                output += std::to_string(num) + ch;
            }
            return output;
        }(input);
    }

    return input.length();
}