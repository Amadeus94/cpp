#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void tolower(string &s)
{
    for (char &x : s)
        x = tolower(x);
}

int main()
{
    //
    // 1+4*x<=y/z*5

    for (char ch; cin.get(ch);)
    {
        if (isspace(ch))
        { // if ch is whitespace
            // do nothing
        }
        if (isdigit(ch))
        {
            //read a number
        }
        if (isalpha(ch))
        {
            //read an identifier
        }
        else
        {
            //deal with operators
        }
    }
}