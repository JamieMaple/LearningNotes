#include <iostream>
#include <vector>

template <typename T> void print(const T& li) {
    for (typename T::size_type i = 0; i != li.size(); ++i) {
        std::cout << li.at(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> li = {1, 2, 3, 4};
    print<std::vector<int>>(li);

    return 0;
}

