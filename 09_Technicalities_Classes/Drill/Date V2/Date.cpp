#include <iostream>

using namespace std;

// $9.4.2 version of Date
struct Date
{
    int y, m ,d ;
    Date(int y, int m, int d);
    void add_day(int n);
};

Date::Date(int y, int m, int d){
    // check if y m d is valid date
    if (y < 0 || m < 1 || d < 1 || m > 12 || d > 31)
        cout << "Error";
    // if it is - use it to initialize dd
    this->d = d;
    this->m = m;
    this->y = y;
}



void add_day(Date &dd, int n)
{
}

void tommorow(Date &dd)
{
    bool upDay=false, upMonth=false; 
    if (dd.d == 31)
    {
        dd.d = 1;
        upDay= true;
    }else 
        dd.d++;
    if(upDay){
        if(dd.m==12){
            dd.m =1;
            dd.y++;
        }else {
            dd.m++;
        }
    }
}

void status(Date &dd)
{
    cout << dd.d << endl
         << dd.m << endl
         << dd.y << endl;
}

int main()
{
    Date today(1978,12,31);
    status(today);
    tommorow(today);
    status(today);
}