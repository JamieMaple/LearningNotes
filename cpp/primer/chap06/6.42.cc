#include <iostream>
#include <string>

using std::string;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return (ctr > 1) ? word + ending : word;
}

int main() {
    string success = "success", failure = "failure";

    std::cout << make_plural(1, success, "es") << std::endl;
    std::cout << make_plural(2, success, "es") << std::endl;
    std::cout << make_plural(1, failure) << std::endl;
    std::cout << make_plural(2, failure) << std::endl;

    return 0;
}
