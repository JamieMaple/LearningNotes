#include <iostream>
#include "Sales_item.h"

int main() {
    // total price
    Sales_item total;
    std::cout << "输入你的书本NO：" << std::endl;
    if (std::cin >> total.bookNo) {
        Sales_item item;
        auto price = 0.0;
        while (std::cin >> item.bookNo && item.bookNo == total.bookNo) {
            std::cin >> item.units_sold >> price;
            item.revenue = price * item.units_sold;
            total.units_sold += item.units_sold;
            total.revenue += item.revenue;
        }
        std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
    } else {
        return -1;
    }
    // 1.5.2
    
    // 1.5.3

    return 0;
}
