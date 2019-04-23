#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

int main() {
    char c1[15] = "Hello World";
    char c2[15] = "Hello World";
    std::vector<char*> roster1 = { c1 };
    std::list<char*> roster2 = { c2 };

    std::cout << std::equal(roster1.cbegin(), roster1.cend(), roster2.cbegin()) << std::endl;

    return 0;
}
