#include <iostream>
#include <list>
#include <algorithm>

int main() {
    std::list<int> li = { 1, 2, 3, 4, 0, 7, 8 };
    auto it = std::find(li.crbegin(), li.crend(), 0);
    std::cout << *it << std::endl;

    return 0;
}
