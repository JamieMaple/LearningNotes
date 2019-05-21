#include <iostream>
#include "strvec.h"

int main() {
    StrVec v;

    std::cout << v.size() << " " << v.capacity() << std::endl;

    v.push_back("hello");
    v.push_back("world");

    std::cout << v.size() << " " << v.capacity() << std::endl;

    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }

    v.push_back("world");
    std::cout << v.size() << " " << v.capacity() << std::endl;

    return 0;
}
