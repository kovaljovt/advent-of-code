#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

std::vector<std::vector<std::string>> parseInput(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<std::vector<std::string>> data;
    while (std::getline(input, line)) {
        std::vector<std::string> row;
        for (char c : line) {
            row.emplace_back(1, c);
        }
        data.push_back(row);
    }
    return data;
}


std::vector<std::string> parseInput2(const std::string &filePath) {
    std::fstream input(filePath);
    std::string line;
    std::vector<std::string> data;
    while (std::getline(input, line)) {
        data.push_back(line);
    }
    return data;
}


std::vector<std::vector<std::string>> transposeData(const std::vector<std::vector<std::string>> &data) {
    std::vector<std::vector<std::string>>
            transposedData(data[0].size(), std::vector<std::string>(data.size()));
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            transposedData[j][i] = data[i][j];
        }
    }
    return transposedData;
}


int part1(const std::string &path) {
    std::vector<std::vector<std::string>> data = parseInput(path);
    std::vector<std::vector<std::string>> transposedData = transposeData(data);
    int result = 0;

    std::string gammaRate;
    std::string epsilonRate;

    for (int i = 0; i < transposedData.size(); i++) {
        int ones = 0;
        int zeros = 0;
        for (int j = 0; j < transposedData[i].size(); j++) {
            if (transposedData[i][j] == "1") ones++;
            if (transposedData[i][j] == "0") zeros++;
        }
        (ones > zeros) ? gammaRate += "1" : gammaRate += "0";
        (ones < zeros) ? epsilonRate += "1" : epsilonRate += "0";
    }

    result += std::stoi(gammaRate, nullptr, 2) * std::stoi(epsilonRate, nullptr, 2);

    return result;
}


int update(std::vector<bool>& fitsCriteria, const std::vector<std::vector<int>> &values, const int acceptableVal, const int index, std::vector<int>& digitSum) {
    int nNotFitC = 0;
    for (int i = 0; i < values.size(); i++) {
        if (values[i][index] != acceptableVal && fitsCriteria[i]) {
            fitsCriteria[i] = false;
            nNotFitC++;
            for (int j = 0; j < digitSum.size(); j++) {
                digitSum[j] -= values[i][j];
            }
        }
    }
    return nNotFitC;
}


int convertToBinary(const std::vector<int>& binVec) {
    const auto s = binVec.size();
    int binVal = 0;
    for (int i = 0; i < s; i++) {
        binVal += (binVec[s - i - 1]) << i;
    }
    return binVal;
}



int part2(const std::string &path) {
    std::vector<std::string> data = parseInput2(path);

    int result;
    std::vector<std::vector<int>> values = {};

    for(auto& line : data) {
        values.emplace_back();
        for(char ch : line) {
            values.back().emplace_back(ch - '0');
        }
    }

    auto valuesCount = values.size();
    auto digitsCount = values[0].size();

    std::vector<int> digitSum(digitsCount);
    for (const auto& value : values) {
        for (int i = 0; i < digitsCount; i++) {
            digitSum[i] += value[i];
        }
    }

    int o2 = 0;
    int co2 = 0;
    const auto digitSumO = digitSum;
    auto fitCriteriaCount = valuesCount;
    std::vector<bool> fitsCriteria(valuesCount, true);

    for (int index = 0; index < digitsCount; index ++) {
        if (digitSum[index] * 2 >= fitCriteriaCount) {
            fitCriteriaCount -= update(fitsCriteria, values, 1, index, digitSum);
        } else {
            fitCriteriaCount -= update(fitsCriteria, values, 0, index, digitSum);
        }
        if (fitCriteriaCount == 1) {
            const auto o2Index = std::distance(std::begin(fitsCriteria), std::find(std::begin(fitsCriteria), std::end(fitsCriteria), true));
            o2 = convertToBinary(values[o2Index]);
            break;
        }
    }

    fitCriteriaCount = valuesCount;
    fitsCriteria = std::vector<bool>(valuesCount, true);
    digitSum = digitSumO;

    for (int index = 0; index < digitsCount; index ++) {
        if (digitSum[index] * 2 >= fitCriteriaCount) {
            fitCriteriaCount -= update(fitsCriteria, values, 0, index, digitSum);
        } else {
            fitCriteriaCount -= update(fitsCriteria, values, 1, index, digitSum);
        }
        if (fitCriteriaCount == 1) {
            const auto co2Index = std::distance(std::begin(fitsCriteria), std::find(std::begin(fitsCriteria), std::end(fitsCriteria), true));
            co2 = convertToBinary(values[co2Index]);
            break;
        }
    }

    result = co2 * o2;
    return result;
}


int main() {
    std::string path = R"(/home/tibor/Desktop/advent-of-code/2021/Day03/Day03.txt)";
    std::cout << part1(path) << '\n';
    std::cout << part2(path) << '\n';
    return 0;
}