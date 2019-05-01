#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include "text_query.h"

using std::string;

TextQuery::TextQuery(std::ifstream& in): content(new text_group_type) {
    string line, word;

    while (std::getline(in, line)) {
        std::istringstream in_str(line);

        content->push_back(line);
        while (in_str >> word) {
            if (word_map.find(word) == word_map.end()) {
                word_map[word].reset(new line_num_group_type);
            }
            word_map[word]->insert(content->size() - 1);
        }
    }
}

QueryResult TextQuery::query(const string& word) const {
    auto it = word_map.find(word);
    if (it == word_map.end()) {
        static auto no_data = std::make_shared<line_num_group_type>();
        return QueryResult(word, no_data, content);
    }
    return QueryResult(word, it->second, content);
}

std::ostream& print(std::ostream& output, const QueryResult& result) {
    output << result.get_word() << " occurs " << result.size() << " ";

    if (result.size() > 1) {
        output << "times\n";
    } else {
        output << "time\n";
    }

    //for (auto it = result.begin(); it != result.end(); ++it) {
        //output << "(line " << *it+1 << ") "<< result.str_at(*it) << std::endl;
    //}

    for (auto it = result.begin(); it != result.end(); ++it) {
        ConstStrBlobPtr p(*result.get_file(), *it);
        output << "(line " << *it + 1 << ") "<< p.deref() << std::endl;
    }

    return output;
}

void runQuery(std::ifstream& infile) {
    TextQuery tq(infile);

    while (true) {
        std::cout << "enter word to look for, or !q to quit: ";

        string s;
        if (!(std::cin >> s) || s == "!q") {
            break;
        }
        print(std::cout, tq.query(s)) << std::endl;
    }
}

