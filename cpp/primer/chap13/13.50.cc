#include <iostream>
#include <cstring>
#include <vector>
#include <memory>
#include <utility>

class String {
    public:
        String();
        String(const char *t);
        String(const String&);
        String(String&&) noexcept;
        String& operator=(const String);
        String& operator=(String&&) noexcept;
        ~String();
        const char* c_str();
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

String::String(String&& t) noexcept : s(t.s) {
    t.s = nullptr;
}

String& String::operator=(String&& t) noexcept {
    free();
    s = t.s;
    t.s = nullptr;
    
    return *this;
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

void String::free() {
    if (s) {
        auto size = strlen(s) + 1;
        std::for_each(s, s + size + 1, [this](char &ch) { alloc.destroy(&ch); });
        alloc.deallocate(s, size);
    }
}

String::~String() {
    free();
}

const char* String::c_str() {
    if (s) {
        return s;
    }

    return "";
}

int main() {
    std::vector<String> v;

    v.push_back("hello");
    String s("world");
    v.push_back(s); // copy assignment happened
    std::cout << v.size() << " " << v.capacity() << std::endl;
    v.push_back(String("Hello World"));
    std::cout << v.size() << " " << v.capacity() << std::endl;

    return 0;
}
