#include <iostream>

int main() {
    int i = 1, *p = &i;

    std::cout << i << " p: " << p << ", " << *p << std::endl;

    *p = 2;

    std::cout << i << " p: " << p << ", " << *p << std::endl;
    return 0;
}
