#include <iostream>
#include <string>

void replaceString(std::string &s, const std::string &source, const std::string &target) {
    for (std::string::size_type i = 0; i != s.size();) {
        if (s.substr(i, source.size()) == source) {
            s.replace(i, source.size(), target);
            i += target.size();
        } else {
            i++;
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
