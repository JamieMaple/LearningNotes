#include <iostream>
#include "1/Sales_item.h"

int main() {
    Sales_item item, total;

    if (std::cin >> item) {
        total = item;
        while (std::cin >> item) {
            if (compareIsbn(total, item)) {
                total += item;
            }
        }
    } else {
        return 1;
    }

    std::cout << total << std::endl;

    return 0;
}
