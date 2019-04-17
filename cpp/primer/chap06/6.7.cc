#include <iostream>

int count() {
    static unsigned counts = 0;
    return counts++;
}

int main() {
    
    for (auto i = 0; i != 10; i++) {
        std::cout << count() << std::endl;
    }

    return 0;
}
