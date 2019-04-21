#include <iostream>
#include <vector>

void printVectorCapacityAndSize(std::vector<int> &v) {
    std::cout << "size: " << v.size() << "\t" << "capacity: " << v.capacity() << std::endl;
}

int main() {
    std::vector<int> v;
    printVectorCapacityAndSize(v);
    v.reserve(10);
    for (int i = 0; i < 40; i++) {
        v.push_back(i);
        printVectorCapacityAndSize(v);
    }
    v.reserve(1024);
    printVectorCapacityAndSize(v);
    v.shrink_to_fit();
    printVectorCapacityAndSize(v);

    return 0;
}
