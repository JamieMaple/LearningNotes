#include <vector>
#include <string>
#include <memory>
#include "strblob.h"

using std::vector;
using std::string;
using std::make_shared;

// public

StrBlob::StrBlob(): data(make_shared<vector<string>>()) {  }

StrBlob::StrBlob(std::initializer_list<string> li): data(make_shared<vector<string>>(li)) {}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

// private
void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}
