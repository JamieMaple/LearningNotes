#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> li = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    auto current = li.cbegin(), previous = li.cbefore_begin();

    while (current != li.cend()) {
        if (*current & 0x1) {
            current = li.erase_after(previous);
        } else {
            previous = current;
            ++current;
        }
    }

    for (auto it = li.cbegin(); it != li.cend(); ++it) {
        std::cout << " " << *it;
    }

    std::cout << std::endl;

    return 0;
}
