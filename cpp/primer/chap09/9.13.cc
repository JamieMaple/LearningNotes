#include <iostream>
#include <vector>
#include <list>

int main() {
    std::list<int> li = { 1, 2, 3, 4 };
    std::vector<int> v(li.begin(), li.end());

    std::vector<double> v0(li.begin(), li.end());
    std::vector<double> v1(li.begin(), li.end());

    return 0;
}
