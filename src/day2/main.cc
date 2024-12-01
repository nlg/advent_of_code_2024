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


TEST_CASE("task1", "[basic]") {
  std::vector<int> l1 = {3, 4, 2, 1, 3, 3};
  std::vector<int> l2 = {4, 3, 5, 3, 9, 3};
  REQUIRE(task1(l1, l2) == 11);
}

TEST_CASE("task1", "[input]") {
  auto [l1, l2] = read_file("input");
  REQUIRE(task1(l1, l2) == 1938424);
}
