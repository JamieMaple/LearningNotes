#include <iostream>
#include <vector>

using std::vector;

int main() {
    // c++ 11
    vector<int> v1 = { 0, 1, 1, 2 };
    vector<int> v2 = { 0, 1, 1, 2, 3, 5, 8 };
    auto isPrefix = true;

    for (auto it1 = v1.cbegin(), it2 = v2.cbegin(); it1 != v1.cend() && it2 != v2.cend(); ++it1, ++it2) {
        if (*it1 != *it2) {
            isPrefix = false;
        }
    }

    std::cout << "Is Prefix? " << (isPrefix ? "true" : "false") << std::endl;

    return 0;
}
