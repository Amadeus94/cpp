#include <iostream>
using namespace std;

int main()
{
    int a;
    int b;
    int c;
    int d;

    // By default input >> operater assumes decimal notation - but you can tell it to read hexadecimal or octal ingers
    //    cin >> a >> hex >> b >> oct >> c >> d;
    //    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
    // if you type  1234 4d2 2322 2322
    // it will yield 1234   1234    1234    1234


///////////////////////////////////////////////////////////////////////////////////////////////

    // You can get >> to accept and correctly interpret the 0 and 0x prefixes 
        // you do this by "unset" all the defaults 

    // stream member function unsetf() clears the flag (or flags) given as argument 
    cin.unsetf(ios::dec); // don't assume decimal ( so that 0x can mean hex)
    cin.unsetf(ios::oct); // don't assume octal ( so that 12 can mean twelve)
    cin.unsetf(ios::hex); // don't assume hexadeicmal    ( so that 12 can mean twelve)

    // if you type  1234 0x4d2 02322 02322
    // it will yield 1234   1234    1234    1234
    cin >> a >> b >> c >> d;
    cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
}