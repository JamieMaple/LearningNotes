#include <iostream>

using std::string;

int main() {
    string total, s;

    while (true) {
        total += s;

        if (!(std::cin >> s)) {
            break;
        }

        if (total != "") {
            total += " ";
        }
    }

    std::cout << total << std::endl;

    return 0;
}
