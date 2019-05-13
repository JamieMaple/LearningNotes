#include <iostream>
#include <string>

using std::string;

class Employee {
    public:
        Employee() = default;
        Employee(const string& s): name(s), _id(id_factory++) {  }
        Employee(const Employee&) = delete;
        Employee& operator=(Employee&) = delete;
        const int id() const { return _id; }
    private:
        static int id_factory;
        string name;
        int _id;
};

int Employee::id_factory = 0;

int main() {
    Employee e1("hello"), e2("world");

    std::cout << e1.id() << " " << e2.id() << std::endl;

    return 0;
}
