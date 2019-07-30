#include <iostream>

template <typename T> class Screen {
    template <typename U> friend std::istream& operator>>(std::istream&, Screen<T>&);
    template <typename U> friend std::ostream& operator<<(std::ostream&, const Screen<U>&);
public:
    Screen(T h, T w) : height(h), width(w) {  }
private:
    T height;
    T width;
};

template <typename T> std::istream& operator>>(std::istream& is, Screen<T>& s) {
    is >> s.height >> s.width;
    return is;
}

template <typename T> std::ostream& operator<<(std::ostream& os, const Screen<T>& s) {
    os << s.height << " " << s.width;
    return os;
}


int main() {
    Screen<int> frame(100, 399);

    return 0;
}
