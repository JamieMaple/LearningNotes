#include <iostream>
#include <string>
#include <deque>

int main() {
    std::deque<std::string> dq;
    std::string str;

    while (std::cin >> str) {
        dq.push_front(str);
    }

    for (auto it = dq.cbegin(); it != dq.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
