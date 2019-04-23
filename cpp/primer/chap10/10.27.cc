#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>

using std::vector;
using std::list;
using std::unique_copy;
using std::back_inserter;

int main() {
    vector<int> v = { 1, 3, 3, 4, 4, 5, 2, 3, 5, 7, 7 };
    list<int> li;

    unique_copy(v.cbegin(), v.cend(), back_inserter(li));

    for (auto i : li) {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}
