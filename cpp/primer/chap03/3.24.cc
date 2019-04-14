#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> v;
    int num;

    while (std::cin >> num) {
        v.push_back(num);
    }

    if (v.empty()) {
        std::cerr << "empty vector !" << std::endl;
        return -1;
    }

    for (auto it = v.cbegin(), last_it = v.cend() - 1; it <= last_it; ++it, --last_it) {
        if (it == last_it) {
            std::cout << *it << std::endl;
        } else {
            std::cout << *it + *last_it << std::endl;
        }
    }

    return 0;
}
