#include <iostream>
#include <vector>

using std::vector;

int main() {
    vector<int> v(11, 0);

    for (unsigned score = 0;std::cin >> score;) {
        ++v[score/10];
    }

    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl; 

    return 0;
}
