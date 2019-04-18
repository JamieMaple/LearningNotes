#include <iostream>
#include <string>

class NoDefault {
    public:
        NoDefault(int a) : a(a) {}
    private:
        const int a;
};

class C {
    public:
        C() : noDefault(0) {  }
    private:
        NoDefault noDefault;
};

int main() {
    C c;

    return 0;
}
