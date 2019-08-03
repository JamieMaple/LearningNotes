#include <memory>
#include <iostream>
#include <string>

class DebugDelete {
public:
    DebugDelete(std::ostream& s = std::cerr) : os(s) {}
    template <typename T> void operator()(T *p) const
    { os << "deleting unique_ptr" << __PRETTY_FUNCTION__ << std::endl; delete p; }
private:
    std::ostream& os;
};

int main() {
    std::unique_ptr<int, DebugDelete> p(new int, DebugDelete());

    return 0;
}
