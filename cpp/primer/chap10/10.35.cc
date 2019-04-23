#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    for (auto it = v.end() - 1; it != v.cbegin() - 1; --it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
