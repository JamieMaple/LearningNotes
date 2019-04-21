#include <iostream>
#include <list>
#include <deque>

int main() {
    std::list<int> li { 1, 2, 3, 4, 5, 6, 7, 8 };
    std::deque<int> odd_deque, even_deque;

    for (auto i : li) {
        if (i % 2 == 0) {
            even_deque.push_back(i);
        } else {
            odd_deque.push_back(i);
        }
    }

    std::cout << "odd deque : " << std::endl;
    for (auto i : odd_deque) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "even deque : " << std::endl;
    for (auto i : even_deque) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
