#include <iostream>

void swap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    int a = 1, b = 2;
    std::cout << "previous : " << a << b << std::endl;
    swap(a, b);
    std::cout << "current : " << a << b << std::endl;
    
    return 0;
}
