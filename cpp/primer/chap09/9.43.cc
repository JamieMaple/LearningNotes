#include <iostream>
#include <string>

void replaceString(std::string &s, const std::string &source, const std::string &target) {
    for (auto it = s.cbegin(); it != s.cend();) {
        // find
        if (std::string(it, it + source.size()) == source) {
            it = s.erase(it, it + source.size());
            it = s.insert(it, target.cbegin(), target.cend());
            it += target.size();
        } else {
            ++it;
        }
    }
}

int main() {
    std::string s = "Hllo World";
    replaceString(s, "Hl", "Hel");
    std::cout << s << std::endl;
    replaceString(s, "ld", "ld!");
    std::cout << s << std::endl;

    return 0;
}
