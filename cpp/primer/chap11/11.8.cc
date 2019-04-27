#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

using std::map;
using std::string;
using std::vector;

int main() {
    map<string, vector<string>> names;
    string family_name;
    
    while (true) {
        std::cout << "plz enter family names:" << std::endl;
        std::cin >> family_name;

        if (family_name == "!q") {
            break;
        }

        string child_name;

        std::cout << "and children: ";

        if (names.count(family_name) < 1) {
            vector<string> v;

            for (std::cin >> child_name; child_name != "!q"; std::cin >> child_name) {
                v.push_back(child_name);
            }
            names[family_name] = v;
        } else {
            std::cerr << "error!" << std::endl;
        }
    }

    for (auto &children : names) {
        std::cout << "Family: " << children.first << std::endl;
        for (auto &child : children.second) {
            std::cout << "\t" << child << std::endl;
        }
    }

    return 0;
}
