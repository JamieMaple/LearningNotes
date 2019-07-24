#ifndef STRBLOB_H
#define STRBLOB_H

#include <vector>
#include <string>
#include <memory>

class StrBlobPtr;

class StrBlob
{
  friend class StrBlobPtr;

public:
  using size_type = std::vector<std::string>::size_type;
  StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
  StrBlob(std::initializer_list<std::string> li);

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();

  std::string &front();
  std::string &back();

  StrBlobPtr begin();
  StrBlobPtr end();

private:
  std::shared_ptr<std::vector<std::string>> data;
  // if data[i] isn't valid, throw error with msg
  void check(size_type i, const std::string &msg) const;
};

inline StrBlob::StrBlob(std::initializer_list<std::string> li) : data(std::make_shared<std::vector<std::string>>(li)) {}

class StrBlobPtr
{
  friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
public:
  StrBlobPtr() : curr(0) {}

  StrBlobPtr(const StrBlob &a, const std::size_t sz = 0) : wptr(a.data), curr(sz) {}

  std::string &deref() const;
  StrBlobPtr &incr();
  StrBlobPtr &decr();

private:
  std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
};

inline std::string &StrBlobPtr::deref() const
{
  auto p = check(curr, "dereference past end");

  return (*p)[curr];
}

inline std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string& msg) const {
  auto ret = wptr.lock();
  if (!ret) {
    throw std::runtime_error("unbond StrBlobPtr");
  }

  if (i >= ret->size()) {
    throw std::out_of_range(msg);
  }

  return ret;
}

inline StrBlobPtr& StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

inline StrBlobPtr StrBlob::begin() {
  return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() {
  auto ret = StrBlobPtr(*this, data->size());
  return ret;
}

inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  auto l = lhs.wptr.lock(), r = rhs.wptr.lock();

  if (l == r) {
    return (!r || lhs.curr == rhs.curr);
  } else {
    return false;
  }
}

inline bool neq(const StrBlob &lhs, const StrBlobPtr &rhs) {
  return !eq(lhs, rhs);
}

#endif
