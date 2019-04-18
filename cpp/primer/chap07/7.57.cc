#include <iostream>
#include <vector>

class Example {
    public:
        static int vecSize;
        static constexpr double rate = 6.5;
        static std::vector<double> vec;
};

int Example::vecSize = 20;
std::vector<double> Example::vec(vecSize);

int main() {
    return 0;
}
