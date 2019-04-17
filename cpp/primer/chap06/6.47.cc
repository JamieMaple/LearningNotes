#include <iostream>
#include <vector>

using std::vector;

void recursiveVector(const vector<int>::iterator &begin, const vector<int>::iterator &end) {
    #ifndef NDEBUG
        std::cerr << "DEBUG : " << "(" << __FILE__ << ") " << __func__ << " " << __DATE__ << std::endl;
        std::cerr << "\t vector size : " << end - begin << std::endl;
    #endif

    if (begin == end) {
        return;
    }


    std::cout << *begin << std::endl;

    recursiveVector(begin + 1, end);
}

int main() {
    vector<int> v = { 1, 2, 3, 4 };

    recursiveVector(v.begin(), v.end());

    return 0;
}
