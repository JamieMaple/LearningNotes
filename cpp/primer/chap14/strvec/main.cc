#include <iostream>
#include <string>
#include "strvec.h"

using std::string;

int main() {
    StrVec v1, v2, v3 = { "Hello", "World" };

    v1 = { "world" };

    std::cout << v1.size() << std::endl;

    v1 = { "world", "Helow" };
    std::cout << v1.size() << std::endl;

    return 0;
}
