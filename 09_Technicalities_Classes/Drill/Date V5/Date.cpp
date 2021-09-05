#include <iostream>

using namespace std;

// $9.7.4 version of Date
// Define date called today
// -.-                tommorow
// Copy today + add 1 by using add_day
// output today and tommorow using a <<operator  defined in 9.8

// Month is not an object - it is a type
// mar is not a data member, it is a enumeration
enum class Month
{
    jan = 1,
    feb,
    mar,
    apr,
    may,
    jun,
    jul,
    aug,
    sep,
    oct,
    nov,
    dec
};

class Year
{
    static const int min = 1800;
    static const int max = 2200;

public:
    class Invalid
    {
    };
    Year(int x) : y{x}
    {
        if (x < min || max <= x)
            throw Invalid{};
    }
    int year() { return y; }

private:
    int y;
};

class Date
{
public:
    Date(Year y, Month m, int d);

    //const
    Month month() const { return m; };
    Year year() const { return y; };
    int day() const { return d; };

    //non-const
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
private:
    Year y;
    Month m;
    int d;
};

Date::Date(Year yy, Month mm, int dd) : y{yy}, m{mm}, d{dd}
{
 // check if y m d is valid date
    if (m < Month::jan || d < 1 || m > Month::dec || d > 31)
        cout << "Error";
}

void Date::add_day(int n)
{
    bool upDay = false, upMonth = false;
    if (this->d == 31)
    {
        this->d = 1;
        upDay = true;
    }
    else
        this->d++;
    if (upDay)
    {
        if (this->m == Month::dec)
        {
            this->m = Month::jan;
            int currentYear = this->y.year();
            this->y = Year(++currentYear);
        }
        else
        {
            int current = static_cast<int>(this->m);
            this->m = Month(current++);
        }
    }
}

std::ostream &operator<<(std::ostream &os, Date &d)
{
    return os << '(' << d.day()
              << ',' << int(d.month())
              << ',' << d.year().year() << ')';
}

int main()
{
    Date today(Year(2000), Month::dec, 31);
    Date tommorow(Year(2000), Month::dec, 31);
    tommorow.add_day(1);
    std::cout << today << tommorow;
}