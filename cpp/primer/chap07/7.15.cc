#include <iostream>
#include <string>

struct Person {
    Person() = default;
    Person(const std::string &s, const std::string &addr, const int age) :
        name(s), address(addr), age(age) {}
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

    unsigned short age = 0;
    std::string name;
    std::string address;
};

int main() {
    Person p;

    std::cin >> p.age >> p.name >> p.address;

    std::cout << p.age << " " << p.getName() << " " << p.getAddress() << std::endl;

    return 0;
}
