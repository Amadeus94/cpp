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
        this->namesVector.push_back(name);
    }
    cin.clear();
}; // reads a series of names

void Name_pairs::read_ages()
{
    cin.clear();
    int age;
    for (size_t i = 0; i < this->names().size(); i++)
    {
        cin >> age;
        this->agesVector.push_back(age);
    }
}; // prompts the user for an age for each name

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
    vector<string> name2 = this->names();
    for (size_t i = 0; i < name2.size(); i++)
    {
        for (size_t j = 0; j < name2.size(); j++)
        {
            if (this->names().at(j) > this->names().at(i))
            {

                swap(this->namesVector.at(j), this->namesVector.at(i));
                swapAge(this->agesVector.at(j), this->agesVector.at(i));
            }
        }
    }
}; // sorts the name vector in alphabetical order and reorganizes the age vector to match;

//Exercise 03
// Define << == !=
ostream &operator<<(ostream &os, const Name_pairs np)
{
    os << "#"
       << "\t"
       << "name\tage" << endl;
    for (size_t i = 0; i < np.ages().size(); i++)
    {
        os << i + 1 << ".\t" << np.names().at(i) << "\t" << np.ages().at(i) << endl;
    }
    return os;
}; // prints out the name[i], age[i] pair  ( One per line ) in the order determined by the name vector

bool operator==(const Name_pairs &n1, const Name_pairs &n2)
{
    return n1.ages() == n2.ages() && n1.names() == n2.names();
}

bool operator!=(const Name_pairs &n1, const Name_pairs &n2)
{
    return !(n1 == n2);
}

int main()
{
    Name_pairs ns;
    ns.read_named();
    ns.read_ages();
    Name_pairs ns2;

    cout << endl
         << "Same Before: " << (ns == ns2) << "\t" << (ns != ns2) << endl;
    ns2 = ns;
    cout << "Same After Copy: " << (ns == ns2) << "\t" << (ns != ns2) << endl;

    cout << ns << endl
         << endl;
    ns.sort();
    cout << ns << endl
         << endl;
}