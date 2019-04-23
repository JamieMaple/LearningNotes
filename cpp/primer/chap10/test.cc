#include <iostream>

int main() {
    auto f = [] { return 42; };

    std::cout << std::boolalpha << (1 <=> 2) << std::endl;

    return 0;
}
