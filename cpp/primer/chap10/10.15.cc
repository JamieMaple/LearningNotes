#include <iostream>

int main() {
    int outer = 10;
    auto f = [outer](int a, int b) -> int { return outer + a + b; };

    std::cout << f(1, 3) << std::endl;

    return 0;
}
