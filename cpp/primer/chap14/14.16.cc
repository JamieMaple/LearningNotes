#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
#include <utility>

class String {
    friend std::ostream& operator<<(std::ostream&, const String&);
    friend bool operator==(const String&, const String&);
    friend bool operator!=(const String&, const String&);
    public:
        String();
        String(const char *t);
        String(const String&);
        String& operator=(const String);
        ~String();
        const char* c_str() const { return s; }
    private:
        void free();
        void swap(String &rhs) {
            using std::swap;
            swap(s, rhs.s);
        }
        char* copy_str(const char*);
        std::allocator<char> alloc;
        char *s;
};

std::ostream& operator<<(std::ostream& os, const String& s) {
    auto c = s.c_str();
    while (*c) {
        os << *c++;
    }

    return os;
}

String::String() {
    auto new_s = alloc.allocate(1);
    alloc.construct(new_s, '\0');
    s = new_s;
}

String::String(const char *t) {
    auto size = strlen(t) + 1;
    auto new_s = alloc.allocate(size);
    auto dest = new_s;

    for (size_t i = 0; i != size; ++i) {
        alloc.construct(dest++, *(t+i));
    }

    s = new_s;
}

char* String::copy_str(const char* t) {
    size_t size = strlen(t) + 1;
    auto new_s = alloc.allocate(size);

    for (size_t i = 0; i != size; ++i) {
        *(new_s + i) = *(t + i);
    }

    return new_s;
}

String::String(const String& src) {
    s = copy_str(src.s);
    std::cout << "!!copy constructor call" << std::endl;
}

String& String::operator=(String src) {
    swap(src);
    std::cout << "!!copy assignment call" << std::endl;
    return *this;
}

bool operator==(const String& lhs, const String& rhs) {
    return strcmp(lhs.s, rhs.s) == 0;
}

bool operator!=(const String& lhs, const String& rhs) {
    return !(lhs == rhs);
}

void String::free() {
    auto size = strlen(s) + 1;
    std::for_each(s, s + size + 1, [this](char &ch) { alloc.destroy(&ch); });
    alloc.deallocate(s, size);
}

String::~String() {
    free();
}

int main() {
    String s("Hello World!");
    String s2("Hello World!");

    std::cout << s << std::endl;
    std::cout << std::boolalpha << (s == s2) << (s == "hell") << std::endl;

    return 0;
}

