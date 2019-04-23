#include <iostream>
#include <list>

int main() {
    std::list<int> li = { 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 0 };

    li.sort();
    li.unique();

    for (auto i : li) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
