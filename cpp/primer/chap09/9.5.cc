#include <iostream>
#include <vector>

std::vector<int>::iterator findElement(std::vector<int> &v, int val) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        if (*it == val) {
            return it;
        }
    }

    return v.end();
}

int main() {
    return 0;
}
