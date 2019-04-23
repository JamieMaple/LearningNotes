#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<double> v = { 1.2, 3.4 };

    std::cout << std::accumulate(v.cbegin(), v.cend(), 0.0) << std::endl;

    return 0;
}
