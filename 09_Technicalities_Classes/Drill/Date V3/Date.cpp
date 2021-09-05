#include <iostream>

using namespace std;

// $9.4.3 version of Date
// Define date called today
// -.-                tommorow
// Copy today + add 1 by using add_day
// output today and tommorow using a <<operator  defined in 9.8

class Date
{
    int y, m, d;

public:
    Date(int y, int m, int d);
    void add_day(int n);
    int month() { return m; };
    int year() { return y; };
    int day() { return d; };
};

Date::Date(int y, int m, int d)
{
    // check if y m d is valid date
    if (y < 0 || m < 1 || d < 1 || m > 12 || d > 31)
        cout << "Error";
    // if it is - use it to initialize dd
    this->d = d;
    this->m = m;
    this->y = y;
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
        if (this->m == 12)
        {
            this->m = 1;
            this->y++;
        }
        else
        {
            this->m++;
        }
    }
}


std::ostream& operator<<(std::ostream &os, Date& d)
{
    return os << '(' << d.day()
              << ',' << int(d.month())
              << ',' << d.day() << ')';
}

int main()
{
    Date today(1978, 12, 31);
    Date tommorow(1978, 12, 31);
    tommorow.add_day(1);

    std::cout << today << tommorow;   


}