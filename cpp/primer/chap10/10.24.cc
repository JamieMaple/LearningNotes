#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using std::vector;
using std::string;
using std::find_if;
using std::bind;
using namespace std::placeholders;

inline
bool largerThanStringSize(const string &s, int i) {
    return i > s.size();
}

int main() {
    vector<int> v = { 1, 3, 5, 7, 9 };
    string s = "Hello";

    auto i = find_if(v.cbegin(), v.cend(), bind(largerThanStringSize, s, _1));

    std::cout << *i << std::endl;

    return 0;
}

