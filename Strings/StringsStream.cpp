#include <sstream>
#include <vector>
#include <iostream>

std::vector<int> parseInts(std::string str) {
    std::vector<int> integers;
    std::stringstream ss(str);
    char ch;
    int num;

    while (ss >> num) {
        integers.push_back(num);
        ss >> ch; // Read and discard the comma
    }

    return integers;
}

int main() {
    std::string input;
    std::cin >> input;

    std::vector<int> result = parseInts(input);

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << std::endl;
    }

    return 0;
}
