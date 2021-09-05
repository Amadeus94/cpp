#include "Chrono.h"

namespace Chrono
{
    // Member function definitions:

    Date::Date(int yy, Month mm, int dd) : y{yy}, m{mm}, d{dd}
    {
        if (!is_date(yy, mm, dd))
            throw Invalid{};
    }

    const Date &default_date()
    {
        static Date dd{2001, Month::jan, 1};
        return dd;
    }

    Date::Date()
        : y{default_date().year()},
          m{default_date().month()},
          d{default_date().day()}
    {
    }

    void Date::add_day(int n)
    {
        if (this->d == 31)
        {
            this->d = 1;
            this->add_month(1);
        }
        else
            this->d++;
    }

    void Date::add_month(int n)
    {
        if (this->m == Month::dec)
        {
            this->m = Month::jan;
            this->add_year(1);
        }
        else
        {
            int current = static_cast<int>(this->m);
            this->m = Month(current++);
        }
        //
    }
    void Date::add_year(int n)
    {
        if (m == Month::feb && d == 29 && !leapyear(y + n))
        { // Beware of leap years
            m = Month::mar;
            d = 1;
        }
        this->y += n;
        //
    }
    // Helper functions

    bool is_date(int y, Month m, int d)
    {
        // Assume that y is valid

        if (d <= 0)
            return false; // d must be positive
        if (m < Month::jan || Month::dec < m)
            return false;

        int days_in_month = 31; // Most months have 31 days

        switch (m)
        {
        case Month::feb: // the length of february varies
            days_in_month = (leapyear(y)) ? 29 : 28;
            break;
        case Month::apr:
        case Month::jun:
        case Month::sep:
        case Month::nov:
            days_in_month = 30; // the rest have 30 days
            break;
        }

        if (days_in_month < d)
            return false; // if days in a month is less than the day ? shouldn't it be other way?
        return true;
    }

    // Exercise 10 - Done
    bool leapyear(int y)
    {
        return y % 4 == 0 ? true : false;
    }

    bool operator==(const Date &a, const Date &b)
    {
        return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
    }

    bool operator!=(const Date &a, const Date &b)
    {
        return !(a == b);
    }

    std::ostream &operator<<(std::ostream &os, const Date &d)
    {
        return os << '(' << d.year()
                  << ',' << int(d.month())
                  << ',' << d.day() << ')';
    }

    std::istream &operator<<(std::istream &is, const Date &dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is)
            return is;
        if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
        {                                     // Ooops: format error
            is.clear(std::ios_base::failbit); //set the fail bit
            return is;
        }
        // dd = Date(y,Month(m),d); // update dd
        return is;
    }

    enum class Day
    { // starts @0 index
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        saturday
    };

    //Day day_of_week(const Date&d) //
    Date next_Sunday(const Date &d)
    {
    }
    Date next_weekday(const Date &d)
    {
    }

    Date next_workday(const Date &d){

    };
    Date week_of_year(const Date &d){

    };
}
