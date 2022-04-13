#include <iostream>
using namespace std;

int main(){

int var1 = 17;
int* ptr1 = &var1;

double var2 = 2.71828;
double* ptr2 =&var2;

double var3 = 2.71828;
double* ptr3 =nullptr;


cout << var1 << " " << ptr1 << "\n" << var2 << "  " << ptr2;

cout << "\n" << sizeof(8);

cout << "\n" << ptr3;

}

