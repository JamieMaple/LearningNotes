#include <list>
#include <deque>

int main() {
    std::list<std::deque<int>> list;
    constexpr const char t[] = "abc";
    std::begin(t);

    return 0;
}
