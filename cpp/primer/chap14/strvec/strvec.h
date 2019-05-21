#ifndef STR_VEC_H
#define STR_VEC_H

#include <string>

class StrVec {
    friend bool operator==(const StrVec&, const StrVec&);
    friend bool operator!=(const StrVec&, const StrVec&);
    friend bool operator<(const StrVec&, const StrVec&);
    public:
        StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {  };
        StrVec(const StrVec&);
        StrVec(std::initializer_list<std::string>);
        StrVec& operator=(std::initializer_list<std::string>);
        StrVec& operator=(const StrVec&);
        StrVec(StrVec &&) noexcept;
        StrVec& operator=(StrVec &&rhs) noexcept;
        ~StrVec();
        void push_back(const std::string&);
        void push_back(std::string&&);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        std::string *begin() const { return elements; }
        std::string *end() const { return first_free; }
        void reserve(size_t);
        void resize(size_t, std::string);
        void resize(size_t);
    private:
        std::allocator<std::string> alloc;
        void chk_n_alloc() { if (size() == capacity()) reallocate(); }
        std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
        void free();
        void reallocate();
        std::string *elements;
        std::string *first_free;
        std::string *cap;
};

bool operator==(const StrVec&, const StrVec&);
bool operator!=(const StrVec&, const StrVec&);

#endif

