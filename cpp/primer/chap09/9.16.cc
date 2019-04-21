#include <iostream>
#include <vector>

inline
bool isEqual(std::vector<int> &v1, std::vector<int> &v2) {
    return v1 == v2;
}

int main() {
    std::vector<int> v1 = { 1, 2, 3 }, v2 = { 1, 2, 3, 4 };

    std::cout << std::boolalpha << " " << isEqual(v1, v2) << std::endl;

    return 0;
}
