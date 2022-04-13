#include <iostream>
using namespace std;
// 01 - Define a global int array ga of ten ints initialized to 1,2,4,8,16, etc.
int ga[10] =  {1,2,4,8,16,32,64,128,254, 512};

// 02 - Define a function f() taking an int array argument and an int argument 
//          Indicating the number of elements in the array
void f(int array[] , int n){
    int la [10]; // a

    for(int i=0; i<n; i++) {
        la[i] = array[i];//b
        cout << la[i] << (i!=9? "\n" : "") ; // c
    }

    cout<< endl << endl; 

    // Define a pointer p to an int and initialize it with an array allocatted on the free store with teh same number of
    // elements as the argument array
   
    int* p = new int[10]; // d
    for(int i=0; i<n; i++) {
        p[i] = array[i];       // e
        cout << p[i] << (i!=9? "\n" : "") ; // f
    }

   delete[] p;


}

int factorial (int n){
    int result =1;
    for(int i=n; i>0; i--)
       result*=i; 
    return result;
}

int main(){

    f(ga, 10);
    int aa[10] {
        factorial(1),
        factorial(2),
        factorial(3),
        factorial(4),
        factorial(5),
        factorial(6),
        factorial(7),
        factorial(8),
        factorial(9)
    };

    cout << endl << endl ;

    for(int i=0; i<10; i++){
            cout << aa[i] << endl;
            } 
    
    cout<< endl << endl; 
    f(aa, 10);




}
