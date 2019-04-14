#include <iostream>

using std::begin;
using std::end;

constexpr size_t rows = 3, cols = 4;
using int_array = int[cols];

int main() {
    int_array ia[rows] = {
        { 1, 2, 3, 4 },
        { 2, 3, 4, 5 },
        { 3, 4, 5, 6 },
    };

    // version 1
    for (int_array &outer : ia) {
        for (auto inner : outer) {
            std::cout << inner << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // version 2
    for (auto i = 0; i < rows; i++) {
        for (auto j = 0; j < cols; j++) {
            std::cout << ia[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // version 3
    for (auto i = begin(ia); i != end(ia); i++) {
        for (auto j = begin(*i); j != end(*i); j++) {
            std::cout << *j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
