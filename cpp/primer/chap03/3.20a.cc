#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> v;
    int val = 0, sum = 0;

    while (std::cin >> val) {
        v.push_back(val);
    }

    for (auto i : v) {
        sum += i;
    }

    std::cout << sum << std::endl;

    return 0;
}
