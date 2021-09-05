#include "my.h"
#include "..\..\Bjarnes_Standard_Header\std_lib_facilities.h"


void print_foo(){
    cout << foo << endl; 
}


void print(int i){
    cout << i << endl; 
}


void swap_v(int a, int b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}

void swap_r(int& a,int& b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}


// Can't because this is a constant reference ie can't be modified  - doesn't compile 
void swap_cr(const int& a, const int& b)
{
    int temp;
    temp = a;
  //  a=b; expression must be a modifiable lvalue
  //  b=temp;   error: assignment of read-only reference 'b'
} 

void swap_d(double& a, int& b){
    int temp;
    temp = a;
    a=b;
    b=temp;
}
