#include <iostream>
#include <string>
#include <memory>

using std::string;

int main() {
    size_t n = 100;
    std::allocator<string> alloc;
    auto p = alloc.allocate(n);
    auto q = p;
    string s;

    // read & construct
    while (std::cin >> s && q - p != 100) {
        alloc.construct(q++, s);
    }

    std::cout << "read in words: " << q - p << std::endl;
    auto it = p;
    while (it != q) {
        std::cout << *it++ << std::endl;
    }

    // delete & deallocate
    while (q != p) {
        alloc.destroy(q--);
    }
    alloc.deallocate(p, n);

    return 0;
}
