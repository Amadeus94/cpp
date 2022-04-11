#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs{"test.txt"};
    if (!ifs.good())
        cout << "oh noes";

    vector<int> v(11);



    char c;
    // get() - gets a single character 
    while(ifs.get(c))
    {

        if (isspace(c))
            v.at(0)++;
        if (isalpha(c)) //         is c a letter ('a'...'z', 'A'...'Z') - note: NOT '_'
            v.at(1)++;
        if (isdigit(c)) //         is c a decimal digit ('0'...'9')
            v.at(2)++;
        if (isxdigit(c)) //         is c a hexadecimal digit (decimal digit or 'a'..'f' or 'A'...'F')
            v.at(3)++;
        if (isupper(c)) //         is c an uppercase letter?
            v.at(4)++;
        if (islower(c)) //         is c an lowercase letter?
            v.at(5)++;
        if (isalnum(c)) //         is c a letter or a decimal digit?
            v.at(6)++;
        if (iscntrl(c)) //         ìs c a control character (ASCII 0..31 and 127) ?
            v.at(7)++;
        if (ispunct(c)) //         is c not a letter, digit, whitespace, or invisible control character?
            v.at(8)++;
        if (isprint(c)) //         is c printable(ASCII ''...'~')?
            v.at(9)++;
        if (isgraph(c)) //         is isalpha(c) or isdigit(c) or ispunct(c) (note:nont space)?
            v.at(10)++;
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << i << ".\t\t" << v.at(i) << endl;
    }
    
}