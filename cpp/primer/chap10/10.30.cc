#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main() {
    std::istream_iterator<int> in_it(std::cin), eof;
    std::vector<int> v;

    while (in_it != eof) {
        v.push_back(*in_it++);
    }

    std::sort(v.begin(), v.end());

    std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
