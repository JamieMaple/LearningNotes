#include <iostream>

class Compare {
    int val;
public:
    Compare(int v): val(v) {  }
    bool operator()(int v) {
        return val == v;
    }
};

int main() {
    Compare c(12);

    std::cout << std::boolalpha << c(2) << " " << c(12) << std::endl;

    return 0;
}

