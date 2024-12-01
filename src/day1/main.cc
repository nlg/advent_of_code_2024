// Least common multiple
#include "catch2/catch_test_macros.hpp"
#include "nlglib.hh"
#include <algorithm>
#include <catch2/catch_all.hpp>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string_view>

std::pair<std::vector<int>, std::vector<int>> read_file(const char* filename) {
    std::ifstream inputFile(filename);
    std::vector<int> l1,l2;
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return {};
    }
    std::string line;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        int number1, number2;
        if (iss >> number1 >> number2) {
            l1.push_back(number1);
            l2.push_back(number2);
        } else {
            std::cerr << "Error reading line: " << line << std::endl;
        }
    }
    inputFile.close();
    return {l1, l2};
}

int task1(std::vector<int> &l1, std::vector<int> &l2) {
  std::sort(std::begin(l1), std::end(l1));
  std::sort(std::begin(l2), std::end(l2));
  int sum = 0;
  for (auto i = 0; i < l1.size(); ++i) {
    auto d = std::abs(l1[i] - l2[i]);
    sum += d;
  }
  return sum;
}

// Task 1:
// Given two lists of integers, pair up smallest number in list a, with the
// smallest number in list b, and so on.
TEST_CASE("task1", "[basic]") {
  std::vector<int> l1 = {3, 4, 2, 1, 3, 3};
  std::vector<int> l2 = {4, 3, 5, 3, 9, 3};
  REQUIRE(task1(l1, l2) == 11);
}

TEST_CASE("task1", "[input]") {
  auto [l1, l2] = read_file("input");
  REQUIRE(task1(l1, l2) == 1938424);
}

// Task 2:
// Given two lists of integers, mulitply the number in the first list with the number
// of times it appears in the second list.
int task2(const std::vector<int>& leftList, const std::vector<int>& rightList) {
  std::unordered_map<int, int> frequencyMap;
  int sum = 0;
  for (const auto num : rightList) {
    frequencyMap[num]++;
  }
  for (const auto num : leftList) {
      sum += frequencyMap[num] * num;
  }
  return sum;
}

TEST_CASE("task2", "[basic]") {
  std::vector<int> l1 = {3, 4, 2, 1, 3, 3};
  std::vector<int> l2 = {4, 3, 5, 3, 9, 3};
  REQUIRE(task2(l1,l2) == 31);
}

TEST_CASE("task2", "[input]") {
  auto [l1, l2] = read_file("input");
  REQUIRE(l1.empty() == false);
  REQUIRE(l2.empty() == false);
  REQUIRE(task2(l1, l2) == 22014209);
}
