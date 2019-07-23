#include <iostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price) : bookNo(book), price(sales_price) {  }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; }
    virtual void debug() { std::cout << bookNo << ":\n" << price << std::endl; }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) {  }
    double net_price(std::size_t n) const override;
    virtual void debug() override { Quote::debug(); std::cout << min_qty << " " << discount  << std::endl; }
protected:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(std::size_t n) const {
    if (n >= min_qty) {
        return n * (1 - discount) * price;
    } else {
        return n * price;
    }
}

double print_total(std::ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);

    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due:" << 0 << std::endl;

    return ret;
}

int main() {
    Quote q("no-1", 12);
    Bulk_quote b("no-2", 14, 20, 0.75);

    print_total(std::cout, q, 10);
    print_total(std::cout, b, 10);

    q.debug();
    b.debug();


    return 0;
}
