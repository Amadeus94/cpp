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

string integer_to_roman(int n)
{
    map<int, char> roman_numerals;
    vector<char> vc = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    vector<int> vi = {1, 5, 10, 50, 100, 500, 1000};

    roman_numerals[1] = 'I';
    roman_numerals[5] = 'V';
    roman_numerals[10] = 'X';
    roman_numerals[50] = 'L';
    roman_numerals[100] = 'C';
    roman_numerals[500] = 'D';
    roman_numerals[1000] = 'M';

    string result = "";
    int prev = 0;

    for (int i = vi.size() - 1; i >= 0; i--)
    {
        if (n >= vi.at(i) || prev < vi.at(i))
        {
            prev =vi.at(i);
            n -= vi.at(i);
            result.push_back(vc.at(i));
            i++;
        } else if(prev>=vi.at(i)){
            prev = vi.at(i);
            i++;
            result.push_back(vc.at(i));
            //result.push_back

        }
    }
    return result;
}

Roman_int add(Roman_int r1, Roman_int r2)
{
    cout << "add" << endl;

    // need to make a from int to numeral
    // need to make a from int to numeral
    // need to make a from int to numeral
    return Roman_int(to_string((r1.as_int() + r2.as_int())));
}

Roman_int substract(Roman_int r1, Roman_int r2)
{
    return Roman_int(to_string((r1.as_int() - r2.as_int())));
}

Roman_int multiply(Roman_int r1, Roman_int r2)
{
    cout << "multiply" << endl;
    return Roman_int(to_string((r1.as_int() * r2.as_int())));
}

Roman_int divide(Roman_int r1, Roman_int r2)
{
    return Roman_int(to_string((r1.as_int() / r2.as_int())));
}

int main()
{

    //    cout << "Enter a value and it will be turned into a roman value" << endl;
    //   Roman_int roman("I");
    //   Roman_int roman2("II");
    //   Roman_int roman3("III");
    //   Roman_int roman4("IV");
    //    Roman_int roman5("V");
    //    Roman_int roman6("VI");
    //    Roman_int roman7("VII");
    //    Roman_int roman8("VIII");
    //    Roman_int roman9("IX");
    //    Roman_int roman10("X");
    //
    //
    //    Roman_int roman393("DCCXXVI");
    //
    //    cout << roman.as_int() << endl;
    //    cout << roman2.as_int() << endl;
    //    cout << roman3.as_int() << endl;
    //    cout << roman4.as_int() << endl;
    //    cout << roman5.as_int() << endl;
    //    cout << roman6.as_int() << endl;
    //    cout << roman7.as_int() << endl;
    //    cout << roman8.as_int() << endl;
    //    cout << roman9.as_int() << endl;
    //    cout << roman10.as_int() << endl;
    //
    //
    //    cout << roman393.as_int() << endl;
    //
    //
    // The exercise:
    //    cout << "Roman " << roman7 << " equals " << roman7.as_int() << '\n';

    // calculator
    //    Roman_int a1 = add(roman2, roman3);
    //    cout << "hello";
    //    cout << a1;
    //    cout << add(roman2, roman3) << endl;
    //    cout << multiply(roman2, roman3) << endl;
    //    cout << divide(roman4, roman2) << endl;
    //    cout << substract(roman3, roman2) << endl;
    cout << integer_to_roman(1) << endl;
    cout << integer_to_roman(2) << endl;
    cout << integer_to_roman(3) << endl;
    cout << integer_to_roman(3) << endl;
    cout << integer_to_roman(4) << endl;
    cout << integer_to_roman(5) << endl;
    cout << integer_to_roman(6) << endl;
}