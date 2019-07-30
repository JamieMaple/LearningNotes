#include <iostream>

template <typename T> class C {
public:
    static std::size_t ctr;
};

template <typename T> std::size_t C<T>::ctr = 10;

int main() {

    C<int> c;

    std::cout << C<int>::ctr << std::endl;

    return 0;
}
