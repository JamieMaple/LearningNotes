#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return -1;
    }

    std::string s;

    for (int i = 1; i != argc; i++) {
        s += argv[i];
    }

    std::cout << s << std::endl;

    return 0;
}
