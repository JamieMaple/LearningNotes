#include <iostream>
#include <string>

std::string addPrefixAndSuffix(std::string &name, const std::string &prefix, const std::string &suffix) {
    std::string new_name = name;

    new_name.insert(new_name.cbegin(), prefix.cbegin(), prefix.cend());
    new_name.append(suffix);

    return new_name;
}

int main() {
    std::string s = "Kevin";

    std::cout << "changed: " << addPrefixAndSuffix(s, "Mr.", " III") << std::endl;
    std::cout << "original: " << s << std::endl;

    return 0;
}
