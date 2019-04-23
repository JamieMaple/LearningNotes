#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

void elimdups(std::vector<std::string>& vs)
{
    std::sort(vs.begin(), vs.end());
    auto new_end = std::unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

inline
bool checkSize(const std::string &s, const std::string::size_type sz) {
    return s.size() >= sz;
}

void biggies_partition(std::vector<std::string>& vs, std::size_t sz)
{
    elimdups(vs);

    auto pivot = partition(vs.begin(), vs.end(), std::bind(checkSize, std::placeholders::_1, sz));

    for (auto it = vs.cbegin(); it != pivot; ++it) std::cout << *it << " ";
}

void biggies_stable_partition(std::vector<std::string>& vs, std::size_t sz)
{
    elimdups(vs);

    auto pivot =
        stable_partition(vs.begin(), vs.end(),
                         [sz](const std::string& s) { return s.size() >= sz; });

    for (auto it = vs.cbegin(); it != pivot; ++it) std::cout << *it << " ";
}

int main()
{
    std::vector<std::string> v{"the",  "quick", "red",  "fox", "jumps",
                               "over", "the",   "slow", "red", "turtle"};

    std::vector<std::string> v1(v);
    biggies_partition(v1, 4);
    std::cout << std::endl;

    return 0;
}
