#include <iostream>

using std::string;

int main() {
    string total, s;

    while (std::cin >> s) {
        total += s;
    }

    std::cout << total << std::endl;

    return 0;
}
