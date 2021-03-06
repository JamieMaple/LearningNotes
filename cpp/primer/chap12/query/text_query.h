#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <iostream>
#include "str_blob.h"


using std::string;
using std::shared_ptr;
//using text_group_type = std::vector<string>;
using text_group_type = StrBlob;
using line_num_type = text_group_type::size_type;
using line_num_group_type = std::set<line_num_type>;

class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
        explicit QueryResult(
                const string& s,
                shared_ptr<line_num_group_type> nums,
                shared_ptr<text_group_type> content):
            word(s), line_nums(nums), lines(content) {  }
        line_num_group_type::iterator begin() const { return line_nums->begin(); }
        line_num_group_type::iterator end() const { return line_nums->end(); }
        line_num_group_type::size_type size() const { return line_nums->size(); }
        const string& get_word() const { return word; }
        //string str_at(line_num_type n) const { return *(lines->begin() + n); }
        shared_ptr<text_group_type> get_file() const { return lines; }
    private:
        const string word;
        shared_ptr<line_num_group_type> line_nums;
        shared_ptr<text_group_type> lines;
};

std::ostream& print(std::ostream&, const QueryResult&);

class TextQuery {
    public:
        explicit TextQuery(std::ifstream &in);
        QueryResult query(const string&) const;
    private:
        shared_ptr<text_group_type> content;
        std::map<string, shared_ptr<line_num_group_type>> word_map;
};

void runQuery(std::ifstream&);

#endif /* ifndef TEXT_QUERY_H

 */
