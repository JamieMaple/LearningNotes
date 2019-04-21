#include <iostream>
#include <forward_list>
#include <string>

void findAndInsert(std::forward_list<std::string> &li, const std::string &source, const std::string &target) {
    auto original_size = std::distance(li.cbegin(), li.cend());
    auto prev = li.cbefore_begin();

    for (auto it = li.cbegin();it != li.cend(); prev = it++) {
        if (*it == source) {
            it = li.insert_after(it, target);
        }
    }
    
    auto size = std::distance(li.cbegin(), li.cend());
    if (size == original_size) {
        li.insert_after(prev, target);
    }
}

void printForwardList(std::forward_list<std::string> &li) {
    for (auto &s : li) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::forward_list<std::string> li;

    findAndInsert(li, "Hello", "Hello");
    printForwardList(li);
    findAndInsert(li, "Hello", "Hello");
    printForwardList(li);
    findAndInsert(li, "World", "World");
    printForwardList(li);
    findAndInsert(li, "Hello", "World");
    printForwardList(li);
    findAndInsert(li, "Hello", "Hello");
    printForwardList(li);

    return 0;
}
