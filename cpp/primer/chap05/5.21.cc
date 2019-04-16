#include <iostream>
#include <string>

using std::string;

int main() {
    string s, prev;

    while (std::cin >> s && !s.empty()) {
        if (!isupper(s[0])) {
            continue;
        }
        if (prev == "" || prev != s) {
            prev = s;
            continue;
        }
        std::cout << "Upper and Repeat Word : " << s << std::endl;
        prev = s;
    }

    return 0;
}
