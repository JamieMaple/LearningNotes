#include "strvec.h"
#include <iostream>

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *begin, const std::string *end) {
    auto elem = alloc.allocate(end - begin);
    return {  elem, std::uninitialized_copy(begin, end, elem) };
}

void  StrVec::free() {
    if (elements) {
        std::for_each(elements, first_free, [this](std::string& p) {
            (*this).alloc.destroy(&p);
        });
        alloc.deallocate(elements, capacity());
    }
}

void StrVec::reallocate() {
    auto new_caps = size() ? 2 * size() : 1;
    auto new_elems = alloc.allocate(new_caps);
    auto dest = new_elems;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elem++));
    } 
    free();

    elements = new_elems;
    first_free = dest;
    cap = elements + new_caps;
}

StrVec::StrVec(const StrVec& v) {
    auto group = alloc_n_copy(v.begin(), v.end());
    elements = group.first;
    first_free = cap = group.second;
}

StrVec::StrVec(StrVec &&v) noexcept
: elements(v.elements), first_free(v.first_free), cap(v.cap) {
    v.elements = v.first_free = v.cap = nullptr;
}


StrVec& StrVec::operator=(StrVec&& rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;

        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }

    return *this;
}

StrVec::StrVec(std::initializer_list<std::string> list) {
    auto data = alloc_n_copy(list.begin(), list.end());
    
    elements = data.first;
    first_free = cap = data.second;
}

StrVec& StrVec::operator=(const StrVec& v) {
    auto group = alloc_n_copy(v.begin(), v.end());

    free();
    elements = group.first;
    first_free = cap = group.second;

    return *this;
}

StrVec& StrVec::operator=(std::initializer_list<std::string> li) {
    auto data = alloc_n_copy(li.begin(), li.end());
    free();

    elements = data.first;
    first_free = cap = data.second;

    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(std::string&& s) {
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

void StrVec::reserve(size_t n) {
    if (capacity() >= n) {
        return;
    }
    auto new_elems = alloc.allocate(n);
    auto dest = new_elems;
    auto elems = elements;

    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*elems++));
    }
    free();

    elements = new_elems;
    first_free = dest;
    cap = new_elems + n;
}

void StrVec::resize(size_t n) {
    resize(n, "");
}

void StrVec::resize(size_t n, std::string s) {
    if (n <= size()) {
        while (first_free != elements + n) {
            alloc.destroy(--first_free);
        }
    } else {
        if (n > capacity()) {
            reserve(2 * n);
        }
        for (size_t i = size(); i != n; ++i) {
            alloc.construct(first_free++, s);
        }
    }
}

bool operator<(const StrVec& lhs, const StrVec& rhs) {
    for (size_t i = 0; i < lhs.size() && i < rhs.size(); ++i) {
        auto lval = *(lhs.begin() + i);
        auto rval = *(rhs.begin() + i);

        if (lval == rval) {
            continue;
        } else if (lval < rval) {
            return true;
        } else {
            return false;
        }
    }

    return lhs.size() < rhs.size();
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
    for (size_t i = 0; i < lhs.size() && i < rhs.size(); ++i) {
        if (*(lhs.begin() + i) != *(rhs.begin() + i)) {
            return false;
        }
    }

    return lhs.size() == rhs.size();
}

