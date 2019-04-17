#include <iostream>
#include <string>

class Person {
    public:
        Person() = default;
        Person(const std::string &s, const std::string &addr, const int age) :
            name(s), address(addr), age(age) {}
        Person(std::istream &is) {
            is >> name >> address >> age;
        }

        std::string getName() const { return name; }
        std::string getAddress() const { return address; }
        unsigned short getAge() const { return age; }

    private:
        unsigned short age = 0;
        std::string name;
        std::string address;
};


int main() {
    Person p(std::cin);

    std::cout << p.getAge() << " " << p.getName() << " " << p.getAddress() << std::endl;

    return 0;
}
