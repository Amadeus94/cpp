#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void toUpperCharecter(string &s)
{
    for (char &x : s)
    {
        x = toupper(x); // Changed in place
    }
}

int main()
{
    // Read inputs
    string inFile = "toUpper.txt";
    ifstream ifs{inFile};
    if (!ifs)
        return 1;

    vector<string> strings;
    for (string s; ifs >> s;)
    {
        strings.push_back(s);
    }

    cout << strings.size();

    // Write to file
    string outputFile = "output.txt";
    ofstream ofs{outputFile};
    if (!ofs)
        return 1;
    for (size_t i = 0; i < strings.size(); i++)
    {
        
        ofs << strings.at(i);
        if(i!=strings.size()-1) ofs <<' ';
    }
    

    //        for (string s; ss2 >> s;)
    //        words.push_back(s);
    //
    //void tolower(string &s)
    //{
    //    for (char &x : s)
    //        x = tolower(x);
    //}
    //
    // for (char ch; cin.get(ch);)
    //    {
    //        if (isspace(ch))
    //        { // if ch is whitespace
    //            // do nothing
    //        }
    //        if (isdigit(ch))
    //        {
    //            //read a number
    //        }
    //        if (isalpha(ch))
    //        {
    //            //read an identifier
    //        }
    //        else
    //        {
    //            //deal with operators
    //        }
    //    }
    //    return 0;
}