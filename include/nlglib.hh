#if 0
std::pair<std::vector<int>, std::vector<int>> read_stdin() {
  std::string line;
  std::vector<int> l1, l2;
  while (std::getline(std::cin, line)) {
    std::istringstream iss(line);
    int number1, number2;
    iss >> number1 >> number2;
    l1.push_back(number1);
    l2.push_back(number2);
  }
  return {l1, l2};
}

std::pair<std::vector<int>, std::vector<int>> read_file(const char* filename) {
    ifstream inputFile(filename);
    vector<int> l1,l2;
    if (!inputFile.is_open()) {
        cerr << "Error opening file" << endl;
        return {};
    }
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        int number1, number2;
        if (iss >> number1 >> number2) {
            l1.push_back(number1);
            l2.push_back(number2);
        } else {
            cerr << "Error reading line: " << line << endl;
        }
    }
    inputFile.close();
    return {l1, l2};
}
#endif
