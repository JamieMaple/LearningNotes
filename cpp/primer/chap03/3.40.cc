#include <iostream>
#include <cstring>

int main() {
    char s1[] = { 'H', 'e', 'l', 'l', 'o', '\0' }, s2[] = { ' ', 'w', 'o', 'r', 'l', 'd', '\0' };
    char s3[12];
    strcpy(s3, s1);
    strcat(s3, s2);

    std::cout << s3 << std::endl;

    return 0;
}
