#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <string>
#include <map>
#include <set>
#include <memory>
#include <iostream>
#include "dep/strvec.h"


class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
    public:
        using line_num_group_type = std::set<size_t>;
        explicit QueryResult(
                const std::string& s,
                std::shared_ptr<line_num_group_type> nums,
                std::shared_ptr<StrVec> content):
            word(s), line_nums(nums), lines(content) {  }
        line_num_group_type::iterator begin() const { return line_nums->begin(); }
        line_num_group_type::iterator end() const { return line_nums->end(); }
        line_num_group_type::size_type size() const { return line_nums->size(); }
        const std::string& get_word() const { return word; }
        std::shared_ptr<StrVec> get_file() const { return lines; }
    private:
        const std::string word;
        std::shared_ptr<line_num_group_type> line_nums;
        std::shared_ptr<StrVec> lines;
};

std::ostream& print(std::ostream&, const QueryResult&);

class TextQuery {
    public:
        using line_num_group_type = std::set<size_t>;
        explicit TextQuery(std::ifstream &in);
        QueryResult query(const std::string&) const;
    private:
        std::shared_ptr<StrVec> content;
        std::map<std::string, std::shared_ptr<line_num_group_type>> word_map;
};

void runQuery(std::ifstream&);

#endif /* ifndef TEXT_QUERY_H

 */
