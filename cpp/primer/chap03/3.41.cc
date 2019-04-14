#include <iostream>
#include <vector>

using std::vector;
using std::begin;
using std::end;

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    vector<int> v(begin(arr), end(arr));

    for (auto val : v) {
        std::cout << val << std::endl;
    }

    return 0;
}
