#include <iostream>
#include <vector>

template <typename T> void print(const T& li) {
    for (typename T::const_iterator it = li.cbegin(); it != li.cend(); ++it ) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
}

int main() {
    std::vector<int> li = {1, 2, 3, 4};
    print<std::vector<int>>(li);

    return 0;
}

