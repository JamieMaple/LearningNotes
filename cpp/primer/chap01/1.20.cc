#include <iostream>
#include "1/Sales_item.h"

int main() {
    Sales_item item;

    while (std::cin >> item) {
        std::cout << item << std::endl;
    }

    return 0;
}

