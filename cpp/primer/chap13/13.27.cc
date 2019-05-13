#include <iostream>
#include <string>

class HasPtr {
    public:
        HasPtr(const std::string &s = std::string()):
            ps(new std::string(s)), i(0), count(new std::size_t(1)) {  }
        HasPtr(const HasPtr &o):
            ps(o.ps), i(o.i), count(o.count) { ++*count; }
        HasPtr& operator=(HasPtr&);
        ~HasPtr();
    private:
        std::string *ps;
        int i;
        std::size_t *count;
};

HasPtr::~HasPtr() {
    if (--*count == 0) {
        delete ps;
        delete count;
    }
}

HasPtr& HasPtr::operator=(HasPtr& o) {
    ++*o.count; // 递增自己

    if (--*count == 0) { // 原来的值是否要释放
        delete ps;
        delete count;
    }

    // 指向新的值
    ps = o.ps;
    i = o.i;
    count = o.count;

    return *this;
}

int main() {
    return 0;
}
