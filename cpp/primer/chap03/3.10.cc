#include <iostream>

using std::string;

int main() {
    string s, result;

    if (std::cin >> s) {
        for (auto c : s) {
            if (!ispunct(c)) {
                result += c;
            }
        }
    } else {
        std::cerr << "No input or bad input" << std::endl;
        return -1;
    }
    std::cout << result << std::endl;

    return 0;
}
