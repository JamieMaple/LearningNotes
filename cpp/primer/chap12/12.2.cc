#include <iostream>
#include "strblob.h"

int main() {
    StrBlob b1;
    {
        StrBlob b2 = { "a", "an", "the" };
        b1 = b2;
        b1.push_back("about");
        std::cout << b1.back() << std::endl;
    }
}
