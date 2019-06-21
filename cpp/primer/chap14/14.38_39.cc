#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class StrCmp {
private:
    size_t lo;
    size_t hi;
public:
    StrCmp(size_t lower, size_t upper): lo(lower), hi(upper) {  }
    bool operator()(const std::string& s) const { return lo <= s.size() && s.size() <= hi; }
};

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cerr << "Plz provide a file name" << std::endl;
        return -1;
    }

    std::size_t q1 = 0, q2 = 0;
    StrCmp less_then_10(1, 9);
    std::ifstream in(argv[1]);
    std::string word;

    while (in >> word) {
        if (less_then_10(word)) ++q1;
        else ++q2;
    }

    std::cout << "less than 10: " << q1 << "\nlarger then 10: " << q2 << std::endl;

    return 0;
}
