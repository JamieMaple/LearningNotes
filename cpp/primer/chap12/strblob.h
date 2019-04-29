#ifndef STR_BLOB_H
#define STR_BLOB_H

#include <vector>
#include <string>
#include <memory>

class StrBlob {
    public:
        using size_type = std::vector<std::string>::size_type;
        StrBlob();
        StrBlob(std::initializer_list<std::string>);
        bool empty() const { return data->empty(); };
        void push_back(const std::string &t) { data->push_back(t); };
        void pop_back();
        std::string &front() const;
        std::string &back() const;
    private:
        std::shared_ptr<std::vector<std::string>> data;
        void check(size_type t, const std::string &msg) const;
};

#endif /* ifndef STR_BL */
