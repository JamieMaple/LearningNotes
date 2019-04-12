#include <iostream>

//typedef double wages;
using wages = double;
typedef wages base, *p;

int main() {
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;
    int *null = 0;
    int *p = null;

    std::cout << ival << " " << *pi
        << " " << **ppi << std::endl;

    int *&rp = pi;
    double dval = 3.14;
    const int &ri = dval;
    
    int i = 0, &r = i;

    const int ci = i, &cr = ci;

    auto a = r;
    const auto f = ci;
    auto &g = ci;
    // auto &h = 42 ERROR
    const auto &h = 42;

    const int b = 1;
    const int &bb = b;

    auto &n = i;

    return 0;
}
