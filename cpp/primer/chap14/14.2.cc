#include <iostream>
#include <string>

class Sales_data {
    friend std::ostream& operator<<(std::ostream&, const Sales_data&);
    friend std::istream& operator>>(std::istream&, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    public:
        Sales_data() = default;
        Sales_data(const std::string &s, unsigned n, double p) :
            bookNo(s), units_sold(n), revenue(n*p) {  }
        explicit Sales_data(const std::string &s) : bookNo(s) {  }
        explicit Sales_data(std::istream&);
        std::string isbn() const { return bookNo; }
        Sales_data &combine(const Sales_data&);
        Sales_data& operator+=(const Sales_data&);
    private:
        double avg_price() const;
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0;
};


Sales_data::Sales_data(std::istream &is) {
    is >> *this;
}

inline double Sales_data::avg_price() const {
    return units_sold ? revenue/units_sold : 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;

    return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.combine(rhs);

    return sum;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    return combine(rhs);
}

std::istream& operator>>(std::istream &is, Sales_data& item) {
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    if (is) {
        item.revenue = price * item.units_sold;
    } else {
        item = Sales_data();
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
    os << item.bookNo << " " << item.units_sold << " " << item.avg_price();

    return os;
}

int main() {
    Sales_data item(std::cin);

    std::cout << item << std::endl;

    return 0;
}

