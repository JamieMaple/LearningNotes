#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 3, 5, 7 };

    v = std::move(v);

    std::cout << v.size() << std::endl;
    
    return 0;
}
