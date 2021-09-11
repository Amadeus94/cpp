#include <fstream>

using namespace std;

class Date
{
public:
    int y, m, d;
};

void dont_do_this(ifstream ist)
{
    Date date;
    for (int month; ist >> month;)
        date.m = month;
    //return date;

    // What is the problem?? you write to same datre object each time ... you need create instantiate a new one for each read
}

void do_this(ifstream ist)
{
    for (int month; ist >> month;)
    {
        Date date;
        date.m= month; // creates new date for each read 
        // vector.pushback
    }
}


