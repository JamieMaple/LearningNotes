#include <iostream>

class Base {
public:
    Base(int v): i(v) {  }
private:
    int i;
};

class Derived : Base {
public:
    using Base::Base;
};

int main() {
    Derived d(1);

    return 0;
}

