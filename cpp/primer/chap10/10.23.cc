#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::count_if;

int main() {
    vector<string> v = { "Hellooo", "World", "algorithm", "strings", "vectors" };

    std::cout << count_if(v.cbegin(), v.cend(), [](const string s) { return s.size() > 6; }) << std::endl;

    return 0;
}
