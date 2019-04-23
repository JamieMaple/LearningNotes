#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using std::vector;
using std::list;

void printList(list<int> &li) {
    for (auto i : li) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    list<int> v1, v2, v3;

    auto it1 = std::inserter(v1, v1.begin());
    auto it2 = std::back_inserter(v2);
    auto it3 = std::front_inserter(v3);

    for (auto i : v) {
        *it1 = i;
        *it2 = i;
        *it3 = i;
    }

    printList(v1);
    printList(v2);
    printList(v3);

    return 0;
}
