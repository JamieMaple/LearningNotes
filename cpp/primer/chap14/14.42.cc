#include <iostream>
#include <functional>
#include <vector>
#include <string>

using std::placeholders::_1;

int main() {
    std::vector<int> v0 = { 0, 1, 2, 10, 1025, 2048 };
    std::vector<std::string> v1 = { "Hello", "World", "pooh", "Hello", "pooh" };

    auto count = std::count_if(v0.cbegin(), v0.cend(), std::bind(std::greater<int>(), _1, 1024));

    auto first_found = std::find_if(v1.cbegin(), v1.cend(), std::bind(std::equal_to<std::string>(), _1, "pooh"));

    std::transform(v0.cbegin(), v0.cend(), v0.begin(), std::bind(std::multiplies<int>(), _1, 2));
    
    std::cout << count << "\n" << *first_found << std::endl;

    for (auto &val : v0) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
