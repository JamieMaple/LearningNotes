#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> v;
    int val = 0, sum = 0;

    while (std::cin >> val) {
        v.push_back(val);
    }

    if (v.size() == 0) {
        return -1;
    }

    for (decltype(v.size()) i = 0, j = v.size() - 1; i <= j; i++, j--) {
        if (i != j) {
            sum = v[i] + v[j];
            std::cout << sum << std::endl;
        } else {
            std::cout << v[i] << std::endl;
        }
    }


    return 0;
}
