#include <iostream>
#include <string>

void test(int a) {  }

bool hasUpperCharactor(const std::string &s) {
    for (auto c : s) {
        if (isupper(c)) {
            return true;
        }
    }

    return false;
}

void upperAllWorld(std::string &s) {
    for (auto &c : s) {
        c = toupper(c);
    }
}

int main() {
    std::string s = "ste";
    const int a = 1;

    test(a);
    upperAllWorld(s);
    std::cout << hasUpperCharactor("steEa") << s << std::endl;

    return 0;
}
