#include <iostream>
#include <vector>
#include <list>

int main() {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    std::list<int> li;
    std::vector<int> v;

    auto bg = std::begin(ia), ed = std::end(ia);
    li.assign(bg, ed);
    v.assign(bg, ed);

    for (auto it = li.cbegin(); it != li.cend();) {
        if (*it & 1) {
            it = li.erase(it);
        } else {
            ++it;
        }
    }

    for (auto it = v.cbegin(); it != v.cend(); ) {
        if (!(*it & 1)) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }

    for (auto val : li) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    for (auto val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
