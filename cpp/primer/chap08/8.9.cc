#include <iostream>
#include <string>
#include <sstream>

std::istream &read(std::istream &in) {
    std::string s;
    while (in >> s) {
        std::cout << s << std::endl;
    }

    in.clear();

    return in;
}

int main() {
    std::string s = "Hello World, My name is Kevin.";
    std::istringstream in(s);

    read(in);

    return 0;
}
