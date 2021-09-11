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
};

ofstream &operator<<(ofstream &ost, vector<Reading> r)
{
    for (size_t i = 0; i < r.size(); i++)
    {
        ost << '(' << r.at(i).hour << ',' << r.at(i).temperature << ')';
        if (i != r.size() - 1)
            ost << '\n';
    }
    return ost;
}

ifstream &operator>>(ifstream &ist, Reading &rr)
{

    int hour;
    double temp;
    char ch1, ch2, ch3;
    ist >> ch1 >> hour >> ch2 >> temp >> ch3;
    if (!ist)
        return ist;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')')
    {
        ist.clear(ios_base::failbit); // sets state to fail state
        return ist;
    }
    rr = Reading{hour, temp}; //update rr
    return ist;
}

//ofstream& operator<<(ofstream& ost, vector<Reading> r){
//}

vector<Reading> readTemperatureFromFile(ifstream &ist)
{
    vector<Reading> temps;
    int hour;
    double temperature;

    //    while (ist >> hour >> temperature)
    //    {
    //        Reading reading;
    //        reading.hour=hour;
    //        reading.temperature=temperature;
    //    }
    for (size_t i = 0; i < 50; i++)
    {

        /* code */
    }

    return vector<Reading>();
}

void randomTemperatureFileGenerator()
{
    // Try generate a program yourself for it

    vector<Reading> temps;
    int hour;
    double temperature;

    string oname = "raw_temps.txt";
    ofstream ost{oname};
    //    while (ist >> hour >> temperature)
    //    {
    //        Reading reading;
    //        reading.hour=hour;
    //        reading.temperature=temperature;
    //    }
    {
        hour = 0;
        for (size_t i = 0; i < 50; i++)
        {
            //hour = rand() % 24; // 0-23
            temperature = rand() % 40 * 1.1;
            temps.push_back(Reading{hour, temperature});
            hour++;
            hour = hour % 24;
        }
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

double calcMean(const vector<Reading> &r)
{
    double sum = 0;
    double result = 0;
    for (Reading reading : r)
    {
        result += reading.temperature;
    }
    result/=r.size()-1;

    return result;
}

double calcMedian(const vector<Reading> &readings   )
{
    vector<double> r;
    for (Reading read: readings)
    {
        r.push_back(read.temperature);
    }

    double result = r.size()-1 % 2==0 ? r.at(r.size()/2) :  r.at((r.size()/2) +1) ;

    return result;
}

void exercise03(vector<Reading> reading){
    double mean   = calcMean(reading);
    double median = calcMedian(reading) ;
    cout << endl << "mean: " << mean << endl << "median: " << median;
}

//Exercise 04
//  Modify the store_rtemps.cpp program from ex 02 to 
//      include a temperature suffix for c for celcius
//      or f for fahrenheit
// then test test each temperature, convwerting the celcius reading to fahrenheit before putting them into the vector .... ie
//      ie (2,23f) sohould be converted to celcius if we want celcius 

int main()
{
    // randomTemperatureFileGenerator();
    vector<Reading> r = exercise02();
    exercise03(r);
    return 0;
}