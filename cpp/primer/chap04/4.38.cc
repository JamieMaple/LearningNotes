#include <string>

using std::string;

int main() {
    char s[3] = "he";
    const string ss = "hello";

    int i;
    double d;
    const string *ps = &ss;
    char *pc = s;
    void *pv;

    pv = const_cast<string*>(ps);
    i = static_cast<int>(*pc);
    pv = &d;

    return 0;
}
