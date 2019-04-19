#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct PersonInfo {
    string name;
    vector<string> phones;
};

inline
bool valid(const string &s) {
    return !s.empty() && isdigit(s[0]);
}

inline
string format(const string &s) {
    return s.substr(0, 3) + "-" + s.substr(3, 3) + "-" + s.substr(6);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        std::cout << "No args provided" << std::endl;
        return -1;
    }

    std::ifstream inFile(argv[1]);
    std::istringstream inStr;
    string line, word;
    vector<PersonInfo> people;

    if (!inFile) {
        std::cout << "Error when open and read file : " << argv[1] << std::endl;
        return -1;
    }

    while (std::getline(inFile, line)) {
        PersonInfo person;
        if (inStr.fail()) {
            inStr.clear();
        }
        inStr.str(line);
        inStr >> person.name;
        while (inStr >> word) {
            person.phones.push_back(word);
        }
        people.push_back(person);
    }

    for (const auto &person : people) {
        std::ostringstream formatted, bad;
        for (const auto &phone : person.phones) {
            if (valid(phone)) {
                formatted << " " << format(phone);
            } else {
                bad << " " << phone;
            }
        }
        if (bad.str().empty()) {
            std::cout << person.name << " : " << formatted.str() << std::endl;
        } else {
            std::cout << "input error: invalid number" << bad.str() << std::endl;
        }
    }

    return 0;
}
