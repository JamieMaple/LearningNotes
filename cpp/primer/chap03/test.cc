#include <iostream>

using std::string;

int main() {
    const char ca[] = { 'h', 'e', 'l', 'l', 'o' };
    const char t[] = { '1', '2', '3' };
    const char *cp = ca;

    while (*cp) {
        std::cout << *cp << std::endl;
        ++cp;
    }

    return 0;
}
