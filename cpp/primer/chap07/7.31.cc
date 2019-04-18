#include <iostream>

class Y;

class X {
    public:
        Y *yp;
};

class Y {
    public:
        X x;
};

int main() {
    return 0;
}
