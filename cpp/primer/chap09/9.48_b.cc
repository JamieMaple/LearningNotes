#include <iostream>
#include <string>

int main() {
    std::string nums = "01234567890";
    std::string alpha = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    std::string s = "ab2c3d7R4E6";

    for (std::string::size_type pos = 0;
            (pos = s.find_first_not_of(nums, pos)) != std::string::npos; ++pos) {
        std::cout << "find a alpha, index : " << pos << std::endl;
    }

    for (std::string::size_type pos = 0; 
            (pos = s.find_first_not_of(alpha, pos)) != std::string::npos; ++pos) {
        std::cout << "find a number, index : " << pos << std::endl;
    }

    return 0;
}
