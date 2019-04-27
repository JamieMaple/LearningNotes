#include <iostream>
#include <vector>
#include <string>
#include <utility>

using std::string;
using std::vector;
using std::pair;

int main() {
    vector<pair<string, int>> v;
    string s;
    int num;

    while (std::cin >> s >> num) {
        v.push_back(std::make_pair(s, num));
        v.push_back(pair<string, int>(s, num));
        v.push_back({ s, num });
        v.emplace_back(s, num);
    }

    for (auto &p : v) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    return 0;
}
