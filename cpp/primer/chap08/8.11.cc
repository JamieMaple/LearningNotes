#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
    std::string name;
    std::vector<std::string> phones;
};

int main() {
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    //std::stringstream record;

    while (std::getline(std::cin, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        //record << line;
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }

    for (auto it = people.cbegin(); it != people.cend(); ++it) {
        std::cout << it->name << " : \n\t";
        for (auto &phone : it->phones) {
            std::cout << phone << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
