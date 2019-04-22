#include <iostream>
#include <vector>
#include <string>

int sumStringVector(std::vector<std::string> &v) {
    int sum = 0;

    for (auto &s : v) {
        sum += std::stoi(s);
    }

    return sum;
}

double sumStringVectorToDouble(std::vector<std::string> &v) {
    double sum = 0;

    for (auto &s : v) {
        sum += std::stod(s);
    }

    return sum;
}



int main() {

    return 0;
}
