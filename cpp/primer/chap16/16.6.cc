#include <iostream>

template <typename T, unsigned L> void print(const T (&p)[L]) {
    for (const T& v : p) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

template <typename T, unsigned L> T* begin(T (&p)[L]) {
    return p;
}

template <typename T, unsigned L> T* end(T (&p)[L]) {
    return p + L;
}

int main() {
    char s[] = "Hello World";
    int a[4] = { 1, 2, 3 };

    print(s);
    print(a);

    std::cout << (end(a) - begin(a)) << std::endl;

    return 0;
}