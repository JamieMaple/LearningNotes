#include <iostream>
#include <string>
#include <cstring>

int main() {
    char arr1[] = "Hello ";
    char arr2[] = "World!";
    size_t len = strlen(arr1) + strlen(arr2) + 1;
    char *arr = new char[len]();

    strcat(arr, arr1);
    strcat(arr, arr2);

    std::cout << arr << std::endl;

    delete[] arr;

    std::string s1("Hello "), s2("World!");
    char *up = new char[s1.length() + s2.length() + 1]();
    strcat(up, (s1 + s2).c_str());

    std::cout << up << std::endl;

    delete[] up;

    return 0;
}
