#include <iostream>
#include <string>

using std::string;

int str_cmp(const char *s1, const char *s2) {
    for (int i = 0; i < strlen(s1) && i < strlen(s2); ++i) {
        if (*(s1 + i) != *(s2 + i)) {
            return *(s1 + i) - *(s2 + i);
        }
    }
    return strlen(s1) - strlen(s2);
}

int main() {
    char s1[] = { 'H', 'e', 'l', 'l', 'o', '!', '\0' }, s2[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    string str1 = s1, str2 = s2;

    std::cout << "string array compare " << strcmp(s1, s2) << std::endl;
    std::cout << "string array self compare " << str_cmp(s1, s2) << std::endl;
    std::cout << "string array compare " << (str1 == str2 ? "equal" : "not equal") << std::endl;

    return 0;
}
