#include <iostream>
#include <iomanip>
using namespace std;

int main()
{


    // floating format only applies to floats 
    cout << 1290390123 << endl;  // prints all numbers because it is a integer
    cout << 1290390123.0; // prints 1290409e+10

    // By default, a flaoting point value is printed using six total digits using the
    //  defaultfloat format ie:
//    cout << 1234.567 << endl;   // prints out as 1234.57
//    cout << 1.23456789 << endl; // prints out as 1.23457
//    cout << 1234567 << endl
//         << endl; // prints out as 1234567
//
//    //Try this
//    cout << 1234567.89 << endl;                 // 1.23457e+06     .. defaults to scientific
//    cout << defaultfloat << 1234567.89 << endl; // 1.23457e+06
//    cout << fixed << 1234567.89 << endl;        // 1234567.890000
//    cout << scientific << 1234567.89 << endl;   // 1.234568e+06         // slightly different from others as it doesn't round uip and then use scientific
//                                                //        ^ Notice 8 instead of 7 as its the case with two above
//
//    cout << 1029381029381092; // prints exact number ... hence why the commas are the one you should be afraid of

    /////////////////////////   SetPrecision    ////////////////////////////////////////
    cout << 1234.56789 << '\t'                          //1234.57       // 6 total
         << fixed << 1234.56789 << '\t'                 // 1234.567890  // All after comma + 0
         << scientific << 1234.56789 << '\n' << endl ;  // 1.234568e+03 // first 6 are precise - 7th is rounded up

    // setprecision(5)
    cout << defaultfloat << setprecision(5) << 1234.56789 << '\t'       // 1234.6       // 5 total 
         << fixed << 1234.56789 << '\t'                                 // 1234.56789   // a
         << scientific << 1234.56789 << '\n' << endl;                   // 1.23457e+03  // first 5 are precise - 6th is rounded up
    //setprecision(8) 
    cout << defaultfloat << setprecision(8) << 1234.56789 << '\t'       // 1234.5679     // 8 total
         << fixed << 1234.56789 << '\t'                                 // 1234.56789000 // 8 after comma
         << scientific << 1234.56789 << '\n';                           // 1.23456789e+03    // 8 are precise 9 is also precise wtf 
 
}