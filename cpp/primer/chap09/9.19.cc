#include <iostream>
#include <string>
#include <list>

int main() {
    std::list<std::string> li;
    std::string str;

    while (std::cin >> str) {
        li.push_front(str);
    }

    for (auto it = li.cbegin(); it != li.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
