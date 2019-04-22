#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "No args provided!" << std::endl;
        return -1;
    }
    constexpr const char * scender = "ertuioaszxcvnm";
    std::string max_word;
    std::ifstream input;

    input.open(argv[1], std::istream::in);

    for (std::string word; input >> word;) {
        if (word.find_first_not_of(scender) == std::string::npos && word.size() > max_word.size()) {
            max_word = word;
        }
    }
    input.close();

    if (max_word != "") {
        std::cout << "word : " << max_word << std::endl;
    } else {
        std::cout << "no word!" << std::endl;
    }

    return 0;
}
