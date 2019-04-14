#include <iostream>

int main() {
    std::string s1, s2;

    std::cin >> s1 >> s2;

    if (s1 < s2) {
        s1 = s2;
    }

    std::cout << "big one: " << s1 << std::endl;

    return 0;
}
