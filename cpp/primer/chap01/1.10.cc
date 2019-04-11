#include <iostream>

int main() {
    int s = 0, b = 0;
    std::cin >> s >> b;

    // swap s and b
    if (s > b) {
        s = s + b;
        b = s - b;
        s = s - b;
    }
    
    for (int i = 0; s + i <= b; i++) {
        std::cout << s + i << " ";
    }

    std::cout << std::endl;
}
