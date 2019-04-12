#include <iostream>

int main() {
    int i = 42;
    auto *p = &i;

    decltype(0.0) j = 1;

    j = 1.1;

    return 0;
}
