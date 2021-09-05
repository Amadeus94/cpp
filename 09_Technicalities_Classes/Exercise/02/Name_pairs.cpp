#include <string>
#include <vector>
#include <iostream>
#include "Name_pairs.h"

using namespace std;

void Name_pairs::read_named()
{
    string name;
    cin >> name;
    while (cin)
    {
        cin >> name;
        this->names.push_back(name);
    }
    cin.clear();
}; // reads a series of names

void Name_pairs::read_ages()
{
    int age;
    for (size_t i = 0; i < this->names.size(); i++)
    {
        cin >> age;
        this->ages.push_back(age);
    }
}; // prompts the user for an age for each name

void Name_pairs::print()
{
    cout << "#"
         << "\t"
         << "name\tage" << endl;
    for (size_t i = 0; i < this->ages.size(); i++)
    {
        cout << i + 1 << ".\t" << this->names.at(i) << "\t" << this->ages.at(i) << endl;
    }
}; // prints out the name[i], age[i] pair  ( One per line ) in the order determined by the name vector

void swap(string &s1, string &s2)
{
    string temp = s1;
    s1 = s2;
    s2 = temp;
}

void swapAge(double &s1, double &s2)
{
    double temp = s1;
    s1 = s2;
    s2 = temp;
}

void Name_pairs::sort()
{
    vector<string> name2 = this->names;
    for (size_t i = 0; i < name2.size(); i++)
    {
        for (size_t j = 0; j < name2.size(); j++)
        {
            if (this->names.at(j) > this->names.at(i))
            {

                swap(this->names.at(j), this->names.at(i));
                swapAge(this->ages.at(j), this->ages.at(i));

            }
        }
    }
}; // sorts the name vector in alphabetical order and reorganizes the age vector to match;

int main()
{
    Name_pairs ns;
    ns.read_named();
    ns.read_ages();
    ns.print();
    ns.sort();
    ns.print();
}