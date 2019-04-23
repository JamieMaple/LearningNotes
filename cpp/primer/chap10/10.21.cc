#include <iostream>
#include <algorithm>

int main() {
    int j = 10;
    auto f = [j] () mutable { return --j > 0 ? true : false; };

    for (int i = 0; i != 20; i++) {
        std::cout << std::boolalpha << f() << std::endl;
    }
}

