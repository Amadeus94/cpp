#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

/*
Write a program that 
    creates a file of data in the form of temperature Reading type defined in 10.5
    For testing, fill the file with a tleast 50 "temperature readings" 
    Call this program 
        "store_temps.cpp 
    and the file it creates 
        "raw_temps.txt"
*/

struct Reading
{

    int hour;
    double temperature;
    char type;
};

ofstream &operator<<(ofstream &ost, vector<Reading> r)
{
    for (size_t i = 0; i < r.size(); i++)
    {
        ost << '(' << r.at(i).hour << ',' << r.at(i).temperature << r.at(i).type << ')';
        if (i != r.size() - 1)
            ost << '\n';
    }
    return ost;
}

ifstream &operator>>(ifstream &ist, Reading &rr)
{

    int hour;
    double temp;
    char type;

    char ch1, ch2, ch3;

    ist >> ch1 >> hour >> ch2 >> temp >> type >> ch3;
    if (!ist)
        return ist;
    if (ch1 != '(' || ch2 != ',' || type != 'f' || ch3 != ')')
    {
        ist.clear(ios_base::failbit); // sets state to fail state
        return ist;
    }
    rr = Reading{hour, temp,type}; //update rr
    return ist;
}
void randomTemperatureFileGenerator()
{
    string oname = "raw_temps.txt";
    ofstream ost{oname};

    vector<Reading> temps;
    int hour = 0;
    double temperature = 0;
    char type='f';

    for (size_t i = 0; i < 50; i++)
    {
        temperature = rand() % 40 * 1.1;
        temps.push_back(Reading{hour, temperature,type});
        hour++;
        hour = hour % 24;
    }
    ost << temps;
}

vector<Reading> exercise02()
{
    vector<Reading> readings;
    string name = "raw_temps.txt";
    ifstream ist{name};

    Reading r;

    while (ist >> r)
    {
        readings.push_back(r);
    }

    for (size_t i = 0; i < readings.size(); i++)
    {
        cout << readings.at(i).hour << ", " << readings.at(i).temperature << "\n";
    }

    return readings;
}



double calcMean(vector<double> readings)
{
    double sum = 0;
    double result = 0;
    for (double r : readings)
    {
        result += r;
    }
    result /= readings.size() - 1;

    return result;
}


bool compareTo(double a, double b){
    return a<b;
}

double calcMedian(vector<double> readings)
{
    sort(readings.begin(), readings.end(), compareTo);
    double result = readings.size() - 1 % 2 == 0 ? readings.at(readings.size() / 2) : readings.at((readings.size() / 2) + 1);

    return result;
}

void exercise03(vector<Reading> readings)
{
    vector<double> s;
    for (size_t i = 0; i < readings.size(); i++)
    {
        s.push_back(readings.at(i).temperature);
    }
    
    double mean = calcMean(s);
    double median = calcMedian(s);
    cout << endl
         << "mean: " << mean << endl
         << "median: " << median;
}

//Exercise 04
//  Modify the store_rtemps.cpp program from ex 02 to
//      include a temperature suffix for c for celcius
//      or f for fahrenheit
// then test test each temperature, convwerting the celcius reading to fahrenheit before putting them into the vector .... ie
//      ie (2,23f) sohould be converted to celcius if we want celcius
vector<Reading> exercise04()
{
    vector<Reading> readings;
    string name = "raw_temps.txt";
    ifstream ist{name};

    Reading r;

    while (ist >> r)
    {
        if(r.type=='f')
            r.type='c';
        readings.push_back(r);
    }

    for (size_t i = 0; i < readings.size(); i++)
    {
        cout << readings.at(i).hour << ", " << readings.at(i).temperature << readings.at(i).type  <<"\n";
    }

    return readings;
}

int main()
{
    randomTemperatureFileGenerator();
    vector<Reading> r = exercise04();
//    //exercise03(r);
    return 0;
}