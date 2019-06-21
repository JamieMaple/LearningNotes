#include <iostream>
#include <string>
#include <vector>

using std::string;

class PrintString {
    public:
        PrintString(std::istream& in = std::cin): is(in) {  }
        std::string operator()() {
            string line;

            if (std::getline(is, line)) {
                return line;
            } else {
                return "";
            }
        }
    private:
        std::istream& is;
};

int main() {
    std::vector<string> content;
    PrintString printer(std::cin);
    string line;

    while ((line = printer()) != "!q") {
        content.push_back(line);
    }

    return 0;
}
