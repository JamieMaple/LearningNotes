#include <iostream>
#include <map>
#include <set>

int main() {
    std::map<int, std::set<int>> m;

    std::cout << m[1].size() << std::endl;

    return 0;
}
