#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include "strblob.h"

using std::vector;
using std::string;

class StrBlobPtr {
    public:
        StrBlobPtr(): curr(0) {}
        StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) {}
        string& deref() const;
        StrBlobPtr &incr();
        bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }
    private:
        std::shared_ptr<vector<string>> check(std::size_t, const string&) const;
        std::weak_ptr<vector<string>> wptr;
        std::size_t curr;
};

std::shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i, const string &msg) const {
    auto ret = wptr.lock();

    if (!ret) {
        throw std::runtime_error("unbond StrBlobPtr");
    }
    if (i >= ret->size()) {
        throw  std::out_of_range(msg);
    }

    return ret;
}

string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return (*this);
}

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this, 0);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, this->data->size());
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "No input file selected!" << std::endl;
        return -1;
    }

    std::ifstream input(argv[1]);
    string line;
    StrBlob blob;

    while (std::getline(input, line)) {
        blob.push_back(line);
    }
    input.close();

    for (auto bg = blob.begin(), ed = blob.end(); bg != ed; bg.incr()) {
        std::cout << bg.deref() << std::endl;
    }

    return 0;
}

