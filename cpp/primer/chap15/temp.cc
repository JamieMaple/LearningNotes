#include <iostream>
#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const std::string& book, double sales_price) : bookNo(book), price(sales_price) {  }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const { return n * price; };
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string& book, double price, std::size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string& book, double p, std::size_t qty, double disc) : Disc_quote(book, p, qty, disc) {  }
    double net_price(std::size_t n) const override;
};

double Bulk_quote::net_price(std::size_t n) const {
    if (n >= quantity) {
        return n * (1 - discount) * price;
    } else {
        return n * price;
    }
};

double print_total(std::ostream& os, const Quote& item, size_t n) {
    double ret = item.net_price(n);

    os << "ISBN: " << item.isbn()
       << " # sold: " << n << " total due:" << 0 << std::endl;

    return ret;
}

int main() {
    Quote q;
    Bulk_quote b;
    // Disc_quote err_quote;

    print_total(std::cout, q, 10);
    print_total(std::cout, b, 10);

    return 0;
}
