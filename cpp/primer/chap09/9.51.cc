#include <iostream>
#include <string>
#include <array>

class Date
{
private:
    static const std::array<std::string, 12> months;
    unsigned year = 1970;
    unsigned month = 1;
    unsigned day = 1;
public:
    explicit Date(int d, int m, int y) : day(d), month(m), year(y) {  };
    explicit Date(const std::string&);
    unsigned getMonFromStr(const std::string &s);
    void print();
};

const std::array<std::string, 12> Date::months  = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

Date::Date(const std::string &s) {
    constexpr const char * delimter = " ,/";
    auto month_delimter_pos = s.find_first_of(delimter);
    month = getMonFromStr(s.substr(0, month_delimter_pos));
    // day
    auto day_delimter_pos = s.find_first_of(delimter, month_delimter_pos + 1);
    day = std::stoul(s.substr(month_delimter_pos + 1, month_delimter_pos - day_delimter_pos - 1));
    // year
    year = std::stoul(s.substr(day_delimter_pos + 1));
}

unsigned Date::getMonFromStr(const std::string &s) {
    if (isdigit(s[0])) {
        return std::stoul(s);
    }

    for (auto it = months.cbegin(); it != months.cend(); ++it) {
        if (s.find(*it) != std::string::npos) {
            return it - months.cbegin() + 1;
        }
    }

    return 0;
}

void Date::print() {
    std::cout << this->year << " " << this->month << " " << this->day << std::endl;
}


int main() {
    {
        auto date = Date("January 1,1900");
        date.print();
    }
    {
        auto date = Date("3/12/1901");
        date.print();
    }
    {
        auto date = Date("Jan 20 2019");
        date.print();
    }

    return 0;
}


