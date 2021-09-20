#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <string>

/*
Roman_int class should hold Roman numerals(as ints)

*/
bool isValid(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (
            s.at(i) == 'I' ||
            s.at(i) == 'V' ||
            s.at(i) == 'X' ||
            s.at(i) == 'L' ||
            s.at(i) == 'C' ||
            s.at(i) == 'D' ||
            s.at(i) == 'M')
        {
            return true;
        }
    }
    return false;
}

class Roman_int
{
public:
    int total;
    int as_int();
    std::string roman_value;
    Roman_int(std::string roman_numeral) : roman_value{roman_numeral}
    {
        if (!isValid(roman_value))
            throw;
    }
    Roman_int(){};

private:
    //Roman numerals
    int I = 1;    //1
    int V = 5;    // 5
    int X = 10;   //10
    int L = 50;   // 50
    int C = 100;  // 100
    int D = 500;  // 500
    int M = 1000; // 1000
};

std::ostream &operator<<(std::ostream &os, const Roman_int &roman)
{
    return os << roman.roman_value;
}

std::istream &operator>>(std::istream &is, Roman_int &roman)
{

    is >> roman.roman_value;
    if (!isValid(roman.roman_value))
    {
        std::cout << "error";
        throw;
    }

    return is;
}