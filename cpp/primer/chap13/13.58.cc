#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Foo {
    public:
        Foo sorted() &&;
        Foo sorted() const &;
    private:
        vector<int> data;
};

Foo Foo::sorted() && {
    std::cout << "sort &&" << std::endl;
    std::sort(data.begin(), data.end());

    return *this;
}

//Foo Foo::sorted() const & {
    //Foo ret(*this);

    //std::sort(ret.data.begin(), ret.data.end());

    //return ret;
//}

//Foo Foo::sorted() const & {
//!Warning: recursion
    //std::cout << "sort const &" << std::endl;
    //Foo ret(*this);
    //return ret.sorted();
//}

Foo Foo::sorted() const & {
    std::cout << "sort const &" << std::endl;
    return Foo(*this).sorted();
}

int main() {
    Foo foo;

    foo.sorted();

    return 0;
}
