#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using std::vector;
using std::string;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;

int main(int argc, char **argv) {
    if (argc <= 1) {
        return -1;
    }

    vector<string> words;  
    ifstream input(argv[1]);
    istream_iterator<string> in_it(input), eof;
    ostream_iterator<string> out_it(std::cout, " ");

    while (in_it != eof) {
        words.push_back(*in_it++);
    }

    for (auto &word : words) {
        *out_it++ = word;
    }

    *out_it = "\n";

    return 0;
}
