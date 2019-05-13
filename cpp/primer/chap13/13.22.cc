#include <iostream>
#include <string>

using std::string;

class HasPtr {
    public:
        HasPtr(const string& t = string()): s(new string(t)), i(0) {  }
        HasPtr(const HasPtr& o): s(new string(*o.s)), i(o.i) {  }
        HasPtr& operator=(const HasPtr& o) {
            auto new_s = new string(*o.s);
            delete s;
            s = new_s;
            i = o.i;
            return *this;
        }
        ~HasPtr() { delete s; }
    private:
        string *s;
        int i;
};

int main() {
    HasPtr h;
    return 0;
}
