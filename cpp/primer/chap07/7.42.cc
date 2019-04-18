#include <iostream>
#include <string>

class Person {
    public:
        Person(const std::string &s, const std::string &addr, const int age) :
            name(s), address(addr), age(age) {
            std::cout << "Person three args constructor" << std::endl;
        }
        Person() : Person("", "", 0) {
            std::cout << "default constructor" << std::endl;
        };
        Person(std::istream &is) {
            std::cout << "istream constructor" << std::endl;
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
    Person p(std::cin), p2;

    std::cout << p.getAge() << " " << p.getName() << " " << p.getAddress() << std::endl;

    return 0;
}
