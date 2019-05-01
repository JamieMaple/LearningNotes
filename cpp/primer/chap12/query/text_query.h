#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <iostream>

#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

using std::string;
using text_group_type = std::vector<string>;
using line_num_type = text_group_type::size_type;
using line_num_group_type = std::set<line_num_type>;

class QueryResult {
    public:
        explicit QueryResult(
                const string &s,
                std::shared_ptr<line_num_group_type> nums,
                std::shared_ptr<text_group_type> content):
            word(s), line_nums(nums), lines(content) {  }
        line_num_group_type::iterator begin() const { return line_nums->begin(); }
        line_num_group_type::iterator end() const { return line_nums->end(); }
        line_num_group_type::size_type size() const { return line_nums->size(); }
        string &str_at(line_num_type n) const { return lines->at(n); }
        const string &get_word() const { return word; }
    private:
        const string word;
        std::shared_ptr<line_num_group_type> line_nums;
        std::shared_ptr<text_group_type> lines;
};

std::ostream &print(std::ostream&, QueryResult);

class TextQuery {
    public:
        explicit TextQuery(std::ifstream &in);
        QueryResult query(const string&);
    private:
        std::shared_ptr<text_group_type> content;
        std::map<string, std::shared_ptr<line_num_group_type>> word_map;
};

void runQuery(std::ifstream&);

#endif /* ifndef TEXT_QUERY_H

 */
