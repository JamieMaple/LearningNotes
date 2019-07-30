#include <iostream>

template <typename T, unsigned L> void print(const T (&p)[L]) {
    for (const T& v : p) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    char s[] = "Hello World";
    int a[4] = { 1, 2, 3 };

    print(s);
    print(a);

    return 0;
}