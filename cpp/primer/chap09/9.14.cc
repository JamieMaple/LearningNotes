#include <iostream>
#include <vector>
#include <list>
#include <string>

int main() {
    std::list<char const *> li = { "Hello", "World", "me" };
    std::vector<std::string> v;

    v.assign(li.cbegin(), li.cend());

    for (auto &s : v) {
        std::cout << s << std::endl;
    }

    return 0;
}
