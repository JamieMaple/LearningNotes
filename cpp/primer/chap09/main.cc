#include <iostream>
#include <string>

int main() {
    std::string s("Hello");
    s.reserve(100);

    s.push_back('a');

    std::cout << s << std::endl;

    return 0;
}
