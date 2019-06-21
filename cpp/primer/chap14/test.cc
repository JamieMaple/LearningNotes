#include <iostream>

class SmallInt {
public:
    SmallInt(int value = 0): val(value) {  }
    operator int() const { return val; }
private:
    int val;
};

int main() {
    SmallInt c(1);

    int a = c + 1;

    std::cout << a << std::endl;

    return 0;
}
