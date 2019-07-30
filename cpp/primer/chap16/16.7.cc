#include <iostream>

template <typename T, unsigned L> constexpr unsigned size(const T (&arr)[L]) {
    return L;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};

    std::cout << size(a) << std::endl;

    return 0;
}
