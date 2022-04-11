#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string numericalType(string word)
{
    if(word.size()==1){
        return "dec";
    }
    if (word.at(1) == 'x')
        return "hex";
    else if (word.at(0) == '0' && word.size() > 1)
        return "oct";
    return "dec";
}

int numberConverter(string type, string number)
{
    stringstream ss;
    int result = 0;
    if (type == "hex")
    {
        ss << std::hex << number;
        ss >> result;
    }
    else if (type == "oct")
    {
        ss << std::oct << number;
        ss >> result;
    }
    else
    {
        ss << std::dec << number;
        ss >> result;
    }
    return result;
}

void printNumbers(string rawNumber, string numberType, int number)
{
    cout << endl
         << rawNumber << "\t" << numberType << "\t"
         << "converts to\t" << number << "\t"
         << "Decimal";
}

int main()
{
    //prompts the user to enter several integers in any combination of
    //   octal, decimal or hexadecimal using the 0x 0 prefixes
    //   Interprets the numbers correctly
    //   and outputs the correct format in column format like this:
    /*
    0x43    hexadecimal     converts to     67  decimal
    0123    octal           converts to     83  decimal
      65    decimal         converts to     65  decimal
   */

    vector<string> rawNumber;
    vector<string> numberType;
    vector<int> numbers;

    //    string s = "0x43";
    //    stringstream ss{};
    //
    //    ss << std::hex << s;
    //    int i;
    //    ss >> i;
    //    cout << i;
    {
        int intNumber = 0;
        for (string number; cin >> number;)
        {
            rawNumber.push_back(number);
            string type = numericalType(number);
            numberType.push_back(type);
            intNumber = numberConverter(type, number);
            numbers.push_back(intNumber);
        }
    }
    cout << endl
         << "The result is: " << endl;
    for (size_t i = 0; i < rawNumber.size(); i++)
    {
        printNumbers(rawNumber.at(i), numberType.at(i), numbers.at(i));
    }
}