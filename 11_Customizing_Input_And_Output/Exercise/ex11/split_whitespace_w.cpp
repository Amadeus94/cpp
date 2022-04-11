#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


// Write a function split()
// that returns a vector of whitespace-space separated substrings from the argument s
// plus ingore the characters in w 
vector<string> split(const string &s, const string& w)
{
    stringstream ss{s};
    string s2;
    vector<string> v;

    while (ss >> s2){
        // replace w 
        for (size_t i = 0; i < s2.size(); i++)
        {
            for (size_t j = 0; j < w.size(); j++)
            {
                if(s2.at(i) == w.at(j))
                    s2.at(i) =' ';
            }
        }
        v.push_back(s2);
    //v.push_back(" ");
    }
    return v;
}

int main()
{
    vector<string> v = split("Hello there how are you doing", "od");
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v.at(i);
    }
}