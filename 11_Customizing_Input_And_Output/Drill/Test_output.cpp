#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main2()
{
    int birth_year = 1994;
    // output in hexa, oct, dec -- /W manipulators

    cout << "Octal"
         << "\tHexadecimal"
         << "\tDecimal" << endl; // 3712, 7ca, 1994
    cout << showbase << oct << 1994 << "\t" << hex << 1994 << "\t\t" << dec << 1994 << endl
         << endl; // 3712, 7ca, 1994
    // without manipulators
    cout << 03712 << endl
         << 0x7ca << endl
         << 1994 << endl;

    cout << "Birth Year: \t" << 2021 - birth_year << endl
         << endl;

    // 8 - Try reading as octal, ehhexadecimal etc. wioth input 1234 1234 1234 1234
    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d; // 1234      668     4660        4660
    cout << a << "\t" << b << '\t' << c << '\t' << d << '\n';
    // this is all in hexadecimal now ... we take it in as decimal > oct > hexadecimal > hexadecimla
    // tghen print it all out as decimal

    return 0;
}

int main3(int argc, char const *argv[])
{

    // 9 Print the number 1234567.89, three times
    //      with defaultfloat, fixed , scientific
    cout // setprecision is by default(6)
        << defaultfloat << 1234567.89 << endl
        << scientific << 1234567.89 << endl
        << fixed << 1234567.89 << endl            // most accurate presentation - because it is by default takes all numbers then fixed at 6 after comma ..
        << setprecision(0) << 1234567.89 << endl; // most accurate presentation - because it is by default takes all numbers then fixed at 6 after comma ..
                                                  //<< setprecision(3) << 1234567.89 << endl;

    return 0;
}

void friends(string lastName, string firstName, string phone, string email)
{
    cout << '|' << setw(10) << lastName << '|' << setw(13) << firstName << '|' << setw(8) << phone << '|' << setw(20) << email << '|' << endl;
}

int main5(int argc, char const *argv[])
{
    cout << setw(10) << "|Last name" << setw(12) << "|First Name" << setw(9) << "|Phone"
         << "   |" << setw(20) << "Email" << '|' << endl;
    friends("hansen", "karlxas", "20393209", "klark@asla.sds");
    friends("hansen2", "k", "20393209", "klark@asla.sds");
    friends("hansen4", "kar", "20393209", "klark@asla.sds");
    friends("hansen3", "kaj", "20393209", "klark@asla.sds");
    friends("hansen5", "karl", "20393209", "klark@asla.sds");
    return 0;
}

int main53(int argc, char const *argv[])
{
    cout << hex << 10 << "\t" << 10 << endl
         << scientific << 10 << "\t" << 10 << endl
         << setprecision(3) << 10.30203023 << "\t" << 10.30203023 << endl
         << showbase << 10 << "\t" << 10 << endl
         << setw(10) << 10 << "\t" << 10 << endl;

        return 0;
}
int main(int argc, char const *argv[])
{
     // is alphabetic  or numeral
     //cout << isalnum('c') <<  endl << isalnum('1') << endl << isalnum(';');
     // 2      4    0     if not alphabetic or numeral provides 0  otherwise givers > 1    ie 2 or 4  
     cout << fixed << setprecision(0) << 123.88 << endl << 12 ;
     return 0;
}
