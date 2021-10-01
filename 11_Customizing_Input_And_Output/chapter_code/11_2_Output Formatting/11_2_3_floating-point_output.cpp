#include <iostream>
using namespace std;

int main()
{
    cout << 1234.56789 << "\t\t(defaultfloat)\n" // \t\t to line up columns
         << fixed << 1234.56789 << "\t(fixed)\n"
         << scientific << 1234.56789 << "\t(scientific)\n";

    // print out
    /*
    1234.57           (general)
    1234.567890       (fixed)
    1234.578e+003     (scientific)
    */

    //////////////////////////////
    cout << 1234.56789 << '\t'
         << fixed << 1234.56789 << '\t'
         << scientific << 1234.56789 << 'n';

    cout << 1234.56789 << '\n';
    cout << defaultfloat << 1234.56789 << '\t'
         << fixed << 1234.56789 << "\t"
         << scientific << 1234.56789 << "\t\n";

}