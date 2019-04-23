#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::ostream &printVector(std::vector<std::string> &v) {
    for (auto i : v) {
        std::cout << i << " ";
    }
    return std::cout;
}

inline
bool isShorter(std::string &s1, std::string &s2) {
    return s1.size() < s2.size();
}

void elimDups(std::vector<std::string> &v) {
    std::stable_sort(v.begin(), v.end());
    printVector(v) << std::endl;
    std::sort(v.begin(), v.end(), isShorter);
    printVector(v) << std::endl;
    auto unique_end = std::unique(v.begin(), v.end());
    printVector(v) << std::endl;
    v.erase(unique_end, v.end());
    printVector(v) << std::endl;
}

int main() {
    std::vector<std::string> v = { "HelloWorld", "the", "quick", "red", "fox", "TESTTEST", "jumps", "over", "the", "slow", "red", "turtle", "THISIS" };

    elimDups(v);

    return 0;
}
