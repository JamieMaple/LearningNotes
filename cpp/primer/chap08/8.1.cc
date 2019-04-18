#include <iostream>
#include <string>

std::istream &read(std::istream &in) {
    std::string s;

    while (in >> s) {
        std::cout << s << std::ends;
    }

    std::cout << std::endl;
    std::cout << "reset std::cin" << std::endl;
    std::cin.clear();

    return in;
}

int main() {
    read(std::cin);
    read(std::cin);

    return 0;
}
