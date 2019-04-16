#include <iostream>
#include <string>

using std::string;

int main() {
    string s, prev;
    bool isRepeat = false;

    while (std::cin >> s) {
        if (prev == s) {
            isRepeat = true;
            break;
        }
        prev = s;
    }

    if (isRepeat) {
        std::cout << "Repeat: " << s << std::endl;
    } else {
        std::cout << "no repeat word." << std::endl;
    }

    return 0;
}
