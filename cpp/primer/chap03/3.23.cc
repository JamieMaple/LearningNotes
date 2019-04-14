#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> v;

    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        *it *= 2;
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
