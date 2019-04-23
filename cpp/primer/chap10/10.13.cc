#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isNotLargerThanFive(std::string &s) {
    return s.size() < 5;
}

void partition(std::string &s) {
    std::vector<std::string> words;
    std::string::size_type prev = 0;
    auto pos = s.find(' ');

    while (pos != std::string::npos) {
        auto temp = std::string(s, prev, pos - prev);
        words.push_back(temp);
        std::cout << temp;

        prev = pos + 1;
        pos = s.find(' ', prev);
    }
    auto it = std::partition(words.begin(), words.end(), isNotLargerThanFive);
    
    std::cout << std::endl;
    for (; it != words.cend(); ++it) {
        std::cout << *it << " ";
    }
}

int main() {
    std::string s = "HELLOWORLD the quick red fox TESTEST jumps over the slow red turtle LASTLAST";
    partition(s);

    return 0;
}
