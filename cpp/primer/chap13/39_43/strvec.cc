#include "strvec.h"

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *begin, const std::string *end) {
    auto elem = alloc.allocate(end - begin);
    return {  elem, std::uninitialized_copy(begin, end, elem) };
}

void  StrVec::free() {
    if (elements) {
        for (auto p = first_free; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
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

StrVec& StrVec::operator=(const StrVec& v) {
    auto group = alloc_n_copy(v.begin(), v.end());

    free();
    elements = group.first;
    first_free = cap = group.second;

    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

