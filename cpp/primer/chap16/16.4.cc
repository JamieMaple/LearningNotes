#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename T, typename U> T find(T bg, T ed, const U& v) {
    for (T it = bg; it != ed; ++it) {
        if (*it == v) {
            return it;
        }
    }
    return ed;
}

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    auto it = find(v.begin(), v.end(), 5);
    std::cout << *it << std::endl;

    std::list<std::string> li = { "Hello", "World" };

    auto it2 = find(li.begin(), li.end(), "Hello");

    std::cout << *it2 << std::endl;

    return 0;
}