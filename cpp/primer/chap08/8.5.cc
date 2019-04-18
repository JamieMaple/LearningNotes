#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "No args provided" << std::endl;
        return -1;
    }

    std::ifstream in;
    std::vector<std::string> v;
    std::string s;

    in.open(argv[1]);

    if (!in) {
        return -1;
    }

    while (in >> s) {
        if (!s.empty() && !ispunct(s[0])) {
            v.push_back(s);
        }
    }

    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        std::cout << *it << std::endl;
    }

    return 0;
}
