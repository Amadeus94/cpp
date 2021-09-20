#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "Roman.h"
#include <map>

using namespace std;

//Roman to Int
int Roman_int::as_int()
{
    map<char, int> roman_numerals;
    roman_numerals['I'] = 1;
    roman_numerals['V'] = 5;
    roman_numerals['X'] = 10;
    roman_numerals['L'] = 50;
    roman_numerals['C'] = 100;
    roman_numerals['D'] = 500;
    roman_numerals['M'] = 1000;

    int result = roman_numerals[roman_value.at(0)];
    int prev = roman_numerals[roman_value.at(0)];

    // Overthought it  -- --- made very complicated program to solve a very easy problem
    // I have now refactored it to way more simpler code
    for (size_t i = 1; i < roman_value.size(); i++)
    {
        int current = roman_numerals[roman_value.at(i)];
        if (current > prev)
        {
            result -= current;
            prev = current;
        }
        else 
        {
            result += current;
            prev = current;
        }
    }

    return abs(result); // lol
}
int main()
{

    cout << "Enter a value and it will be turned into a roman value" << endl;
    Roman_int roman("I");
    Roman_int roman2("II");
    Roman_int roman3("III");
    Roman_int roman4("IV");
    Roman_int roman5("V");
    Roman_int roman6("VI");
    Roman_int roman7("VII");
    Roman_int roman8("VIII");
    Roman_int roman9("IX");
    Roman_int roman10("X");
    

    Roman_int roman393("DCCXXVI");

    cout << roman.as_int() << endl;
    cout << roman2.as_int() << endl;
    cout << roman3.as_int() << endl;
    cout << roman4.as_int() << endl;
    cout << roman5.as_int() << endl;
    cout << roman6.as_int() << endl;
    cout << roman7.as_int() << endl;
    cout << roman8.as_int() << endl;
    cout << roman9.as_int() << endl;
    cout << roman10.as_int() << endl;


    cout << roman393.as_int() << endl;


    // The exercise:
    cout << "Roman " << roman7 << " equals " << roman7.as_int() << '\n';
}