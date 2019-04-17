#include <iostream>
#include "Chapter6.h"

int main() {
    int n;

    if (std::cin >> n) {
        std::cout << "output : " << fact(n) << std::endl;
    }

    return 0;
}
