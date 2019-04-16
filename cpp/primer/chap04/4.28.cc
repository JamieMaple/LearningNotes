#include <iostream>

struct Sales_item {
    int bookNo;
    double price;
};

int main() {
    std::cout << "char:" << sizeof(char) << std::endl;
    std::cout << "int: " << sizeof(int) << std::endl;
    std::cout << "long: " << sizeof(long) << std::endl;
    std::cout << "long long: " << sizeof(long long) << std::endl;
    std::cout << "float: " << sizeof(float) << std::endl;
    std::cout << "double: " << sizeof(double) << std::endl;
    std::cout << "Sales_item: " << sizeof(Sales_item) << std::endl;
    std::cout << "Sales_item pointer: " << sizeof(Sales_item*) << std::endl;
    std::cout << "int pointer:" << sizeof(int*) << std::endl;
    std::cout << "char pointer:" << sizeof(char*) << std::endl;
    std::cout << "char pointer:" << sizeof(char*) << std::endl;

    return 0;
}
