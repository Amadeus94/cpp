#include <iostream>
namespace Chrono
{
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

    class Date
    {
    public:
        class Invalid{}; // to throw as expcetion

        Date(int y, Month m, int d); // check for valid date and initialize
        Date(); // Default constructor
                    // The default copy operations are fine
                
        // Nonmodifying operations
        int day() const{return d;}
        Month month() const{return m;}
        int year() const{return y;}

        // Modifying operations
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);

        private:
        int y;
        Month m;
        int d;
    };

    bool is_date(int y, Month m, int d); //true for valid date
    bool leapyear(int y); // true if y is a leap year

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    std::ostream& operator<<(std::ostream& os, const Date& d);
    std::istream& operator>>(std::istream& is, Date& dd);

    int day_of_week(const Date& d); // day of the week of d
    Date next_Sunday(const Date d);
    Date next_weekday(const Date& d);


    Date next_workday(const Date d); // assume that any day that is not a saturday or a sunday is a workday
    Date week_of_year(const Date d); // Assume that week 1 is the week with January 1 in it 
                                // and that the first day of a week is a sunday
    

}