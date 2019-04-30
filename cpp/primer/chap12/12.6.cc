#include <iostream>
#include <vector>

using std::vector;

vector<int> *allocVector() {
    return new vector<int>();
}

void readFromInput(vector<int> *vp) {
    int n;

    std::cout << "Plz input:" << std::endl;
    while (std::cin >> n) {
        vp->push_back(n);
    }
}

void getVector(vector<int> *vp) {
    for (auto it = vp->cbegin(); it != vp->cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    auto p = allocVector();

    readFromInput(p);
    getVector(p);
    
    delete p;

    return 0;
}
