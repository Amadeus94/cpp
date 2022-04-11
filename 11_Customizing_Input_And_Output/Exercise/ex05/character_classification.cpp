#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string bigTable(string word)
{
    // For each bogstav write a table
    cout << "char\t"
         << "isspace\t"
         << "isalpha\t"
         << "isdigit\t"
         << "isxdigit\t"
         << "isupper\t"
         << "islower\t"
         << "isalnum\t"
         << "iscntrl\t"
         << "ispunct\t"
         << "isprint\t"
         << "isgraph\t"
         << endl;

    for (size_t i = 0; i < word.size(); i++)
    {
        cout << word.at(i) << "\t" << isspace(word.at(i)) << "\t" << isalpha(word.at(i)) << "\t" << isdigit(word.at(i)) << "\t" << isxdigit(word.at(i)) << "\t\t"
             << isupper(word.at(i)) << "\t" << islower(word.at(i)) << "\t" << isalnum(word.at(i)) << "\t" << iscntrl(word.at(i)) << "\t"
             << ispunct(word.at(i)) << "\t" << isprint(word.at(i)) << "\t" << isgraph(word.at(i))
             << endl;
    }
}

string classify(char c) // Could also make it tab separated
{
    if (isspace(c))
    {
        return "isspace";
    }                    //         is c whitespace('', '\t','\n' etc.?)
    else if (isalpha(c)) //         is c a letter ('a'...'z', 'A'...'Z') - note: NOT '_'
        return "isalpha";
    else if (isdigit(c)) //         is c a decimal digit ('0'...'9')
        return "isdigit";
    else if (isxdigit(c)) //         is c a hexadecimal digit (decimal digit or 'a'..'f' or 'A'...'F')
        return "isxdigit";
    else if (isupper(c)) //         is c an uppercase letter?
        return "isupper";
    else if (islower(c)) //         is c an lowercase letter?
        return "islower";
    else if (isalnum(c)) //         is c a letter or a decimal digit?
        return "isalnum";
    else if (iscntrl(c)) //         ìs c a control character (ASCII 0..31 and 127) ?
        return "iscntrl";
    else if (ispunct(c)) //         is c not a letter, digit, whitespace, or invisible control character?
        return "ispunct";
    else if (isprint(c)) //         is c printable(ASCII ''...'~')?
        return "isprint";
    else if (isgraph(c)) //         is isalpha(c) or isdigit(c) or ispunct(c) (note:nont space)?
        return "isgraph";
}

// Read strings
//   output the character classification of each character
int main()
{
    cout << "\a";
    string word;

    while (cin >> word)
    {
        cout << endl
             << word << endl
             << "######################################" << endl;
        bigTable(word);
        // for (size_t i = 0; i < word.size(); i++)
        // {
        //     cout << endl
        //          << classify(word.at(i));
        // }
    }
}
