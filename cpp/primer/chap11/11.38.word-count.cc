#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string word;
    std::unordered_map<std::string, int> m;

    while (std::cin >> word) {
        ++m[word];
    }

    for (auto &pair : m) {
        std::cout << pair.first << " : " << pair.second << std::endl;
    }

    return 0;
}
