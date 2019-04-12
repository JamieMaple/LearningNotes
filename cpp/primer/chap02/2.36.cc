#include <iostream>

using Sales_data = struct {
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    int a = {3}, b{4};

    decltype(a) c = a;
    decltype((b)) d = a;

    c++;
    std::cout << a << b << c << d << std::endl;
    d++;
    std::cout << a << b << c << d << std::endl;

    const int i(1); 

    auto j = i;
    decltype(i) k = i;
    j++;
    // k++;

    return 0;
}
