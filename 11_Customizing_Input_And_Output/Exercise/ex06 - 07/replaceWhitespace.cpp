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

    // Replace punctuation with whitespace
    //  ".;,?-'"
    // Don't modify characters within a pair of double quotes("")

    bool inQuote;
    string line;

    getline(cin, line);
    // do character replacement as needed:

    // to lower
    for (char &ch : line)
    {
        if (isalpha(ch))
            ch = tolower(ch);
    }

    stringstream ss{line};



/*

string:npos 

It means not found.

It is usually defined like so:

static const size_t npos = -1;
 


*/
    while (line.find("don't") != string::npos) // not sure what npos does
        line.replace(line.find("don't"), 5, "do not");

    while (line.find("can't") != string::npos) // not sure what npos does
        line.replace(line.find("can't"), 5, "cannot");

    for (char &ch : line)
    {
        if (ch == '\"')
            inQuote = !inQuote;
        if (ispunct(ch) && !inQuote && ch != '\"')
            ch = ' '; // to space
    }
    cout << line;
}
