#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>

using std::string;

std::unordered_map<string, string> buildMap(std::ifstream &map_file) {
    std::unordered_map<string, string> m;
    string line;

    while (std::getline(map_file, line)) {
        auto space_pos = line.find(" ");
        auto key = string(line, 0, space_pos);

        if (space_pos < line.size() - 1) {
            m[key] = string(line, space_pos + 1);
        } else {
            throw std::runtime_error("no rule for " + key);
        }
    }

    return m;
}

void transform(std::ostream &output, std::ifstream &input, std::ifstream &input_rule) {
    auto mapped_rule = buildMap(input_rule);
    auto is_first = false;
    string line, word;

    while (std::getline(input, line)) {
        std::istringstream line_input(line);
        is_first = true;

        while (line_input >> word) {
            if (is_first) {
                is_first = false;
            } else {
                output << " ";
            }

            if (mapped_rule.find(word) != mapped_rule.end()) {
                output << mapped_rule[word];
            } else {
                output << word;
            }
        }

        output << "\n";
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        std::cerr << "Not enough args!" << std::endl;
        return -1;
    }

    std::ifstream input(argv[1]), input_rule(argv[2]);
    
    transform(std::cout, input, input_rule);

    std::cout << std::endl;

    return 0;
}
