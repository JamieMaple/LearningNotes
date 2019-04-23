#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::list<int> li;

    std::copy(v.cbegin() + 3, v.cbegin() + 8, std::front_inserter(li));

    for (auto i : li) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
