#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Point
{
    int x, y;
};

std::istream &operator>>(std::ifstream &is, Point &obj)
{
    is >> obj.x >> obj.y;
    return is;
}

// represents a temperature reading
struct Reading
{
    int hour;
    double temperature;
};

void readTempsFromFile()
{
    ifstream ist{string("hello")};

    vector<Reading> temps;
    int hour;
    double temperature;
    while (ist >> hour >> temperature)
    {
        if (hour < 0 || 23 < hour)
            cout << "error";
        temps.push_back(Reading{hour, temperature});
    }
}

// General states
void iostreamStates()
{
    int i = 0;
    cin >> i;
    if (!cin)
    {
        if (cin.bad())
            cout << "cin is bad"; // Stream corrupted: lets gout ouut of here
        if (cin.eof())
            ; // reached end of file  -- no more input to read -  this is often how we want a sequence of input operations to end
    }
    if (cin.fail())
    {
        cin.clear(); // Stream encountered something unexpected
                     // format issues or something --
        // Somehow recover
    }
}

// Recover from fail
void iostreamRecoverFromFail(istream &ist, vector<int> &v, char terminator)
{
    // Read integers from ist into v until we reach eof() or terminator
    for (int i; ist >> i;)
        v.push_back(i);

    // Recovering from the 4 stream states:

    //1. eof
    if (ist.eof())
        return; //Fine - we found the end of file

    //2. bad
    if (ist.bad())
        cout << "error"; // Straem corrupted: lets get out of here
                         // throw exception
    cout << "hello";
    //3. fail  ----
    if (ist.fail())
    { // Clean up the mess at best we can and report the problem

        ist.clear(); // Clear stream state
                     // So that we can look for termiantor
        char c;
        ist >> c; // read a character, hopefully terminator
        cout << c;
        if (c != terminator)
        {                                 // Unexpected character
            ist.unget();                  // put that character back
            ist.clear(ios_base::failbit); // set the state to fail();
                                          // Indicates we found a format error
        }
    }
}

// Recover from fail    - Simplified by using ist.exceptions(ist.exceptions|ios_base::badbit) autoamtilcally throwing exceptiosn
void iostreamRecoverFromFailSimplified(istream &ist, vector<int> &v, char terminator)
{
    for (int i; ist >> i;)
        v.push_back(i);

    if (ist.eof())
        return;

    //    if (ist.bad())
    //        cout << "error";

    //    if (ist.fail())
    //    {

    //Not good() and not bad() and not eof(), ie it must be a fial()
    ist.clear();

    char c;
    ist >> c;

    if (c != terminator)
    {
        ist.unget();
        ist.clear(ios_base::failbit);
    }
}

int main()
{
    ifstream ist{string("numberSeparatedFile.txt")};
    // Make ist autoamatically throw exception since thats what we want for a bad() state
    // The effect is simply that from the statement onward, ist will throw the standard library exception ios_base::failure if it goes bad()
    // Bitwise OR
    ist.exceptions(ist.exceptions() | ios_base::badbit);

    vector<int> v;
    char s = 'k';
    iostreamRecoverFromFail(ist, v, 'k');

    return 0;
}

int mai2()
{
    // Open File
    cout << "please enter input file name: ";
    string iname;
    //  cin >> iname; - If you want them read the file in but cba -- also you need provide FULL name aka separated.txt ... not only separated
    iname = string("numberSeparatedFile.txt");

    ifstream ist{iname};                    // ist is an input stream for the file named name
    if (!ist)                               // Checks if the file was properly opened
        throw "Division by zero condition"; // Did not know I could throw a stirng

    //Read numbers from file
    vector<Point> points;
    for (Point p; ist >> p;)
    {
        points.push_back(p);
    }

    // Output to console
    cout << endl;
    for (int i = 0; i < points.size(); i++)
    {
        cout << i << ".\t"
             << "(" << points.at(i).x << "," << points.at(i).y << ")" << endl;
    }

    //Output to file
    cout << "Please enter name of output file: ";
    string oname;
    cin >> oname;
    ofstream ost{oname};
    if (!ost)
        throw "Can't open output file ";

    return 0;
}

//Opening a file implicitly as part of the cvreation of an ostream or istream and relying on the SCOPE of the stream to take care of the closing the file is ideal
// for instance

void fill_from_file(vector<Point> &points, string &name)
{
    ifstream ist{name};
    if (!ist)
        cout << "error";
}

// The altnernative is relying on open() and close() operations
// but relying on scope minimizes the chances of sometone trying to use a file sttream before it has been attached ot a stream or after it awas closed
// Always test a stream after opening it

void fill_from_file_Via_Operations()
{
    fstream fs;
    fs.open("foo", ios_base::in); // Open for input
    if (!fs)
        cout << "error";
    // read
    fs.close();
}

// A great