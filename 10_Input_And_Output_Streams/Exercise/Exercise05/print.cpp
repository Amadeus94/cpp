#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//const int not
//
//struct Day{
//    vector<double> hour{vector<double>(24, not_a_reading)}
//};

const int not_a_reading = -7777;
;                           // less than absolute zero --- for an hour of a day
const int not_a_month = -1; // used instead of searching an array of all the months ..just represent it here

struct Day
{
    vector<double> hour{vector<double>(24, not_a_reading)}; // vector(size,default_initialization)
};

struct Month
{                           // A month of temperature readings
    int month{not_a_month}; // [0:11] january is 0
    vector<Day> day{32};    // [1:31] One vector of readings per day -- Note: We waste day[0] to keep the code simple
};

struct Year
{                            // A year of temperature readings, organized by month
    int year;                // Positive AD
    vector<Month> month{12}; // [0-11] Jan is 0
};

struct Reading
{
    int day;
    int hour;
    double temperature;
};

istream &operator>>(istream &is, Reading &r)
{
    //ready a temperature reading from is into r
    // format: (3 4 9.7)
    // check format, but don't bother with data validity

    char ch1;
    if (is >> ch1 && ch1 != '(')
    {
        is.unget(); // could it be a reading?
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;

    is >> d >> h >> t >> ch2;
    if (!is || ch2 != ')')
        cout << "error bad reading";
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

void end_of_loop(istream &ist, char term, const string &message)
{
    if (ist.fail())
    {
        ist.clear();
        char ch;
        if (!(ist >> ch && ch == '|'))
            cout << "error - " << message; // uses | as terminator
    }
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading &r)
{
    // rough test
    if (r.day < 1 || 31 < r.day)
        return false;
    if (r.hour < 0 || 23 < r.hour)
        return false;
    if (r.temperature < implausible_min || implausible_max < r.temperature)
        return false;
    return true;
}

istream &operator>>(istream &is, Month &m)
{
    //read a month from is into m
    // format {month feb...}

    char ch = 0;
    if (is >> ch && ch != '{')
    {
        is.unget(); // failed a month reading
        is.clear(ios_base::failbit);
        return is;
    }

    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if (!is || month_marker != "month")
        cout << "error - bad start of month";
    //m.month = month_to_int(mm); // not implemented
    int duplicates = 0;
    int invalids = 0;
    for (Reading r; is >> r;)
    {
        if (is_valid(r)) // not yet implemented
        {
            if (m.day[r.day].hour[r.hour] != not_a_reading)
                ++duplicates;
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else
            invalids++;
    }
    if (invalids)
        cout << "error - Invalid readings in a month" << invalids;
    if (duplicates)
        cout << "duplicate readings in month" << duplicates;
    end_of_loop(is, '}', "bad end of month"); // -- not implemented -- Checks for terminators
    return is;
}

istream &operator>>(istream &is, Year &y)
{
    //read a month from is into m
    // format {year 1972...}

    char ch = 0;
    is >> ch;
    if (ch != '{')
    {
        is.unget(); // failed a Year reading
        is.clear(ios_base::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if (!is || year_marker != "year")
        cout << "error - bad start of year";
    y.year = yy;

    while (true)
    {
        Month m; // get a clean m each time around
        if (!(is >> m))
            break;
        y.month[m.month] = m;
    }

    end_of_loop(is, '}', "bad end of month"); // -- not implemented -- Checks for terminators
    return is;
}

//void print_year(&ofstream ofs, Year y){
//
//};

int main()
{
    // open an input file
    cout << "please enter input file name\n";
    string iname;
    cin >> iname;
    ifstream ifs{iname};
    if (!ifs)
        cout << "Error can't read input file name " << iname;
    ifs.exceptions(ifs.exceptions() | ios_base::badbit); // throw for bad ()

    // open an output file
    cout << "Please enter output file name\n";
    string oname;
    cin >> oname;
    ofstream ofs{oname};
    if (!ofs)
        cout << "can't open output file:" << oname;

    // Read an arbitrary bnumber of years
    vector<Year> ys;
    while (true)
    {
        Year y; // get a freshly initializesd Year each time around
        if (!(ifs >> y))
            break;
        ys.push_back(y);
    }
    cout << "read " << ys.size() << " Yyears of readings\n";

    for (Year &y : ys)
        print_year(ofs, y);
}