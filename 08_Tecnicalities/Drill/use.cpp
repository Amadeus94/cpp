#include "my.h"
#include <iostream>
using namespace std;
int foo = 10; // Always put it in global -- if its extern.... ffs
              // This is like the definition while the other was declaration and this is why we again use the int foo

void test()
{
    int x = 7;
    int y = 9;

    //swap_d(x,y); // must be same tyhpe when ref

    //    swap_cr(x, y);   // Never compiles because it is a constant -- can't but lets just say it did then it owuld sometimes
    swap_r(x, y);
    swap_v(x, y);
    swap_cr(7.7, 9.9);
    //    swap_r(7.7, 9.9);// cannot bind non-const lvalue reference of type 'int&' to an rvalue of type 'int'
    swap_v(7.7, 9.9);
    /////////////////////////////////////////////////////////////////////////////////////////////
    const int cx = 7;
    const int cy = 9;

    //   swap_cr(cx, cy);
    // swap_r(cx, cy); // error: binding reference of type 'int&' to 'const int' discards qualifiers
    swap_v(cx, cy);

    //    swap_cr(7.7, 9.9);
    //  swap_r(7.7, 9.9); // requires reference  - this is local
    swap_v(7.7, 9.9); // ie put consts in value or const experssions
                      //
    double dx = 7.7;
    double dy = 9.9;

    // swap_cr(dx, dy);
    //swap_r(dx, dy); // its a int reference ---- cannot b initialized with double
    swap_v(dx, dy);
    //   swap_cr(7.7, 9.9);
    // swap_r(7.7, 9.9);
    swap_v(7.7, 9.9);
}

void printTest()
{
    int x = 7;
    int y = 9;

    swap_v(x, y);
    cout << x << ";" << y << endl;

    
    swap_r(x, y);
    cout << x << ";" << y << endl;

    /////////////////////////////////////////////////////////////////////////////////////////////
    const int cx = 7;
    const int cy = 9;

    swap_v(cx, cy);
    cout << cx << ";" << cy << endl;


    double dx = 7.7;
    double dy = 9.9;

    swap_v(dx, dy);
    cout << dx << ";" << dy << endl;
}

int main()
{
    //    ::foo = 7; // foo is defined in my.h
    print_foo();
    print(99);

    test();
    printTest();
}