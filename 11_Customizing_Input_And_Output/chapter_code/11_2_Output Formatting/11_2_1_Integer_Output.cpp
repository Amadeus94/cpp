#include <iostream>
using namespace std;

int main()
{
    /*
        \t  tabulation character
        hex informs the stream that nay further integer valeus should be displayed in hexadecimal
        oct     -..-                                                                  octal
        dec     -..-                                                                  decimal

        Notice Styream will continue to display it as octals until changed 

    */
    cout << 1234 << "\t(decimal)\n"
         << hex << 1234 << "\t(hexadecimal)\n"
         << oct << 1234 << "\t(octal)\n";

    cout << "Not over yet: "
         << "\t " << 1234 << endl
         << endl;

    // Birthyear & Date in Hex & Octal:

    cout << dec << 1994 << "\t(decimal)\n"
         << hex << 1994 << "\t(hexadecimal)\n"
         << oct << 1994 << "\t(octal)\n" << endl << endl << endl;

    // showbase -- Shows the prefixes of the current output  
    //             Notice how it also persists and needs to be changed by using noshowbase
    cout << showbase;
    cout << dec << 1994 << "\t(decimal)\n"              // Decimal has no prefix    1994    
         << hex << 1994 << "\t(hexadecimal)\n"          // Hex has 0x prefix        0x7ca 
         << oct << 1994 << "\t(octal)\n";               // oct has 0 prefix         03712

    cout << noshowbase;

    // Print dec via hexa and octa

    cout << noshowbase << dec 
         << 1234
         << endl
         << 0x4d2
         << endl
         << 02322;

}