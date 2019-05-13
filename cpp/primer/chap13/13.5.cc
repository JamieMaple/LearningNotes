#include <iostream>
#include <string>

class HasPtr {
    public:
        HasPtr(const std::string& s = std::string()):
            ps(new std::string(s)), i(0) {  }
        HasPtr(const HasPtr& o):
            ps(new std::string(*o.ps)), i(o.i) {  }
    private:
        std::string *ps;
        int i;
};

int main() {


    return 0;
}

