#include <iostream>

using std::string;

int main() {
    int i = 42;
    auto *p = &i;
    string a("Hello World");
    auto len = a.size();
    int n = -1;

    if (len < n) {
        // true, n to very big
        std::cout << a << std::endl;
    }

    return 0;
}
