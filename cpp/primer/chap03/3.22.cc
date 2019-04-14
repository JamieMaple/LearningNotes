#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int main() {
    vector<string> vvs;

    vvs.push_back("hello world");
    vvs.push_back("world hello!");
    vvs.push_back("");
    vvs.push_back("hello ");
    vvs.push_back("world ");

    for (auto it = vvs.begin(); it != vvs.end() && !it->empty(); ++it) {
        for (auto innerIt = it->begin(); innerIt != it->end(); ++innerIt) {
            *innerIt = toupper(*innerIt);
        }
        for (auto &c : *it) {
            c = toupper(c);
        }
        std::cout << *it << std::endl;
    }

    return 0;
}
