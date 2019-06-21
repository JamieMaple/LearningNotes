#include <iostream>
#include <functional>
#include <vector>

using std::placeholders::_1;

int main() {
    int val;
    std::vector<int> v{ 6, 3 };

    if (std::cin >> val) {
        bool allModed = std::any_of(v.cbegin(), v.cend(), std::bind(std::modulus<int>(), _1, val));
        allModed = !allModed;
        std::cout << std::boolalpha << allModed << std::endl;
    }

    return 0;
}
