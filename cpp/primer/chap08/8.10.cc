#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cerr << "No args provided!" << std::endl;
        return -1;
    }

    std::ifstream inFile(argv[1]);
    std::string line, word;
    std::vector<std::string> v;

    while (std::getline(inFile, line)) {
        v.push_back(line);
    } 

    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::istringstream inLine(*it);
        while (inLine >> word) {
            std::cout << word << std::endl;
        }
    }

    return 0;
}
