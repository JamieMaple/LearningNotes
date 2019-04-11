#include <iostream>
#include "1/Sales_item.h"

int main() {
    Sales_item item1, item2;

    std::cin >> item1 >> item2;

    if (compareIsbn(item1, item2)) {
        std::cout << item1 + item2 << std::endl;
    } else {
        std::cerr << "ERROR: two Sales_item don't have same isbn" << std::endl;
    }

    return 0;
}
