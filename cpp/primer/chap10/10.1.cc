#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v;
    int n, target;

    std::cout << "given target number ?";
    std::cin >> target;

    std::cout << "nums: \n";
    while (std::cin >> n) {
        v.push_back(n);
    }

    std::cout << "target found : " << std::count(v.cbegin(), v.cend(), target) << std::endl;

    return 0;
}
