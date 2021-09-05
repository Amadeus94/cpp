#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <vector>

using namespace std;
struct Reading
{
    int hour;
    double temperature;
};

int main()
{
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if (!ist)
        //error("can't open input file ", iname);
        cout << "Can't open input file " << iname;

    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost{oname};
    if (!ost)
        //error("Can't open output file ", oname);
        cout << "Can't open output file " << oname;

    vector<Reading> temps;
    int hour;
    double temperature;
    while (ist >> hour >> temperature)
    {
        if (hour < 0 || 23 < hour)
            //error("Hour out of range");
            cout << "Hour out of range";
        temps.push_back(Reading{hour, temperature});
    }

    for (size_t i = 0; i < temps.size(); ++i)
    {
        ost << '(' << temps[i].hour << ','
            << temps[i].temperature << ")\n";
        cout << '(' << temps[i].hour << ','
             << temps[i].temperature << ")\n";
    }
}