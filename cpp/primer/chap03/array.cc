#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
    char str[] = "hello";

    string s = str;
    vector<char> vs(std::begin(str), std::end(str));

    return 0;
}
