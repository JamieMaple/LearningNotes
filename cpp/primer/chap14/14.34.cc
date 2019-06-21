#include <iostream>

class Func {
    public:
    int operator()(int a, int b, int c) const {
        if (a) {
            return b;
        } else {
            return c;
        }
    }
};

int main() {
    Func f;

    std::cout << f(0, 2, 3) << std::endl;

    return 0;
}
