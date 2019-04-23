#include <iostream>
#include <vector>
#include <algorithm>

std::ostream &printVector(std::vector<int> &v) {
    for (auto i : v) {
        std::cout << i << " ";
    }
    return std::cout;
}

void elimDups(std::vector<int> &v) {
    std::sort(v.begin(), v.end());
    printVector(v) << std::endl;
    auto unique_end = std::unique(v.begin(), v.end());
    printVector(v) << std::endl;
    v.erase(unique_end, v.end());
    printVector(v) << std::endl;
}

int main() {
    std::vector<int> v = { 9, 8, 1, 3, 6, 9, 10, 1, 3, 4 };

    elimDups(v);

    return 0;
}
