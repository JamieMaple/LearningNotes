#include <iostream>
#include <vector>

int sum(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int main() {
    std::vector<int(*)(int, int)> v;

    v.push_back(sum);
    v.push_back(sub);
    v.push_back(mul);
    v.push_back(divide);

    for (auto func : v) {
        std::cout << func(6, 3) << std::endl;
    }

    return 0;
}
