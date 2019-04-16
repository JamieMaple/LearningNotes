#include <iostream>

int main() {
    int a, b;
    char ch;

    std::cin >> a;

    while (true) {
        try {
            std::cin >> b;
            if (b == 0) {
                throw std::runtime_error("second number can not be zero!");
            }
            std::cout << a/b << std::endl;
            break;
        } catch(std::runtime_error err) {
            std::cout << "Error: " << err.what() << std::endl;
            std::cout << "Try again?(y/n)" << std::endl;
            std::cin >> ch;
            if (ch == 'n') {
                break;
            }
        }
    }

    return 0;
}
