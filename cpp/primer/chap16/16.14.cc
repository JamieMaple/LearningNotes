#include <iostream>

template <typename T> class Screen {
public:
    Screen(T h, T w) : height(h), width(w) {  }
private:
    T height;
    T width;
};

int main() {
    Screen<int> frame(100, 399);

    return 0;
}
