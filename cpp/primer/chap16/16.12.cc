#include <iostream>
#include <string>
#include <vector>
#include <memory>

template <typename T> class BlobPtr;

template <typename T> class Blob {
    friend class BlobPtr<T>;
public:
    using value_type = T;
    using size_type = typename std::vector<T>::size_type;
    Blob() : data(std::make_shared<std::vector<T>>()) {  };
    Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T>>(il)) {  }
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const T &t) { data->push_back(t); } 
    void pop_back();
    T& back();
    T& operator[](const size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    void check(size_type i , const std::string &msg) const;
};

template <typename T> void Blob<T>::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) {
        throw std::out_of_range(msg);
    }
}

template <typename T> T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T> T& Blob<T>::operator[](size_type i) {
    return (*data)[i];
}

template <typename T> void Blob<T>::pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T> class BlobPtr {
public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    T& operator*() const { auto p = check(curr, "dereference past end"); return (*p)[curr]; }
    BlobPtr& operator++();
    BlobPtr& operator--();
    BlobPtr& operator++(int);
    BlobPtr& operator--(int);
private:
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++() {
    ++curr;
    return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--() {
    --curr;
    return *this;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
}

template <typename T> BlobPtr<T>& BlobPtr<T>::operator--(int) {
    BlobPtr ret = *this;
    --*this;
    return ret;
}

int main() {
    Blob<std::string> b;

    b.push_back("Hello World");

    std::cout << b.size() << std::endl;
    
    BlobPtr<std::string> ptr(b);

    return 0;
}


