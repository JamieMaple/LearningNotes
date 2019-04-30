#include <memory>
#include <string>

int main() {
    std::unique_ptr<int> p(new int());

    return 0;
}
