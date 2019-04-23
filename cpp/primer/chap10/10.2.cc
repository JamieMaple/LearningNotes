#include <iostream>
#include <list>
#include <string>
#include <algorithm>

int main() {
    std::list<std::string> li = {"Hello", "World", "Hello", "Hello"};

    std::cout << std::count(li.cbegin(), li.cend(), "Hello") << std::endl;

    return 0;
}
