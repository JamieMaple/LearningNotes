#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> v = { 1, 2, 3, 4, 5, 6 };
    int arr[6];

    for (auto it = v.cbegin(); it != v.cend(); it++) {
        auto n = it - v.cbegin();
        *(arr + n) = *it;
    }

    for (auto val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
