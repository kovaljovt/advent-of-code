#include <iostream>
#include <vector>
#include <algorithm>


std::vector<std::vector<int>> generateCombinations(const std::vector<int>& containers, int k, int start, std::vector<int>& combination);
int part1();
int part2();


int main() {
    std::cout << part1() << '\n';
    std::cout << part2() << '\n';
    return 0;
}


std::vector<std::vector<int>> generateCombinations(const std::vector<int>& containers, int k, int start, std::vector<int>& combination) {
    std::vector<std::vector<int>> combinations = {};

    if (k == 0) {
        combinations.push_back(combination);
        return combinations;
    }

    for (int i = start; i <= containers.size() - k; i++) {
        combination.push_back(containers[i]);
        std::vector<std::vector<int>> subCombinations = generateCombinations(containers, k - 1, i + 1, combination);
        combinations.insert(combinations.end(), subCombinations.begin(), subCombinations.end());
        combination.pop_back();
    }

    return combinations;
}


int part1() {
    int total = 0;
    const std::vector<int> containers = {50, 44, 11, 49, 42, 46, 18, 32, 26, 40, 21, 7, 18, 43, 10, 47, 36, 24, 22, 40};

    for (int i = 1; i < containers.size() - 1; i++) {
        std::vector<int> combination = {};
        std::vector<std::vector<int>> combinations = generateCombinations(containers, i, 0, combination);
        for (const auto& comb : combinations) {
            int sum = 0;
            for (int element : comb) {
                sum += element;
            }
            if (sum == 150) {
                total++;
            }
        }
    }

    return total;
}


int part2()
{
    int total = 0;
    const std::vector<int> containers = {50, 44, 11, 49, 42, 46, 18, 32, 26, 40, 21, 7, 18, 43, 10, 47, 36, 24, 22, 40};
    std::vector<int> min = {};

    for (int i = 1; i < containers.size() - 1; i++) {
        std::vector<int> combination = {};
        std::vector<std::vector<int>> combinations = generateCombinations(containers, i, 0, combination);
        for (const auto& comb : combinations) {
            int sum = 0;
            int cont = 0;
            for (int element : comb) {
                sum += element;
                cont++;
            }
            if (sum == 150) {
                total++;
                min.push_back(cont);
            }
        }
    }

    int target = *std::min_element(min.begin(), min.end());
    int count = 0;

    for(int i = 0; i < min.size(); i++) {
        if(target == min[i]) {
            count++;
        }
    }

    return count;
}