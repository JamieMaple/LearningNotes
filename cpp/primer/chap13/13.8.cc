#include <iostream>
#include <string>

class HasPtr {
    public:
        HasPtr(const std::string& s = std::string()):
            ps(new std::string(s)), i(0) {  }
        HasPtr(const HasPtr& o):
            ps(new std::string(*o.ps)), i(o.i) {  }
        ~HasPtr() { delete ps; }
        HasPtr& operator=(const HasPtr& o);
    private:
        std::string *ps;
        int i;
};

HasPtr& HasPtr::operator=(const HasPtr& o) {
    (*this).ps = new std::string(*o.ps);
    (*this).i = o.i;

    return *this;
}

int main() {


    return 0;
}

