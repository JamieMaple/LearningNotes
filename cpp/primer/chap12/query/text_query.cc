#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include "text_query.h"

using std::string;

TextQuery::TextQuery(std::ifstream &in): content(new text_group_type) {
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

QueryResult TextQuery::query(const string &word) {
    if (word_map.find(word) == word_map.end()) {
        return QueryResult(word, std::make_shared<line_num_group_type>(), content);
    }
    return QueryResult(word, word_map[word], content);
}

std::ostream &print(std::ostream &output, QueryResult result) {
    output << result.get_word() << " occurs " << result.size() << " times\n";

    for (auto it = result.begin(); it != result.end(); ++it) {
        output << "(line " << *it+1 << ") "<< result.str_at(*it) << std::endl;
    }

    return output;
}

void runQuery(std::ifstream &infile) {
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

