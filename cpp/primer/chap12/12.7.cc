#include <iostream>
#include <vector>
#include <memory>

using std::vector;

std::shared_ptr<vector<int>> allocVector() {
    return std::make_shared<vector<int>>();
}

void readFromInput(std::shared_ptr<vector<int>> vp) {
    int n;

    std::cout << "Plz input:" << std::endl;
    while (std::cin >> n) {
        vp->push_back(n);
    }
}

void getVector(std::shared_ptr<vector<int>> vp) {
    for (auto it = vp->cbegin(); it != vp->cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    auto p = allocVector();

    readFromInput(p);
    getVector(p);

    p = nullptr;

    return 0;
}
