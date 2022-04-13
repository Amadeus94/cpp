#include <iostream> 
#include <vector>
using namespace std;


ostream& print_array10(ostream& os, int* a){
    for(int i =0; i<10; i++){
        os << a[i] ;
        if(i!=9)
            os << ",";
    }
    return os;
}

ostream& print_array(ostream& os, int* a, int n){
    for(int i =0; i<n; i++){
        os << a[i] ;
        if(i!=n-1)
            os << ",";
    }
    return os;
}


ostream& print_vector(ostream& os, vector<int> v){
    for(int i =0; i<v.size(); i++){
        os << v[i] ;
        if(i!=v.size()-1)
            os << ",";
    }
    return os;
}


int main(){
//1. Allocate an array of ten ints on the free store using new
    int* tenInts = new int[10] {0,1,2,3,4,5,6,7,8,9};

//2. Print the values of the ten ints to cout
    for(int i =0; i<10; i++){
        cout << tenInts[i] ;
        if(i!=9)
            cout << ",";
    }

    // 3. Deallocate the array using the delete[]
   
    delete[] tenInts;


    //4.  Write a function print_array10(ostream& os, int* a) that prints out the values of a (assumed to have 10 elements)
    // to os
    int* tenInt = new int[10] {0,1,2,3,4,5,6,7,8,9};
    print_array10(cout, tenInt);

    //5.   Allocate an array of ten ints on the free store
    //          Initialize it with the values 100-110
    //          and print out its values
    int* tenInter = new int[10] {100,101,102,103,104,105,106,107,108,109};
    print_array10(cout, tenInter);
    
    
    //6. Allocate an array of 11 ints on the free store ....
    int* elevenInts = new int[11] {100,101,102,103,104,105,106,107,108,109,110};
    for(int i =0; i<11; i++){
           cout << elevenInts[i] ;
           if(i!=9)
               cout << ",";
       }

    // 7. Write out a function print_arraY(ostream& os, int* a, int n)
    cout << endl << endl;
    print_array(cout,elevenInts, 11);

    //8. Allocate 20 ints 100-119- and print it
    cout << endl << endl; 
    int* twentyInts = new int[20] {100,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,116,117,118,119};

    print_array(cout,twentyInts, 20);

    // 9. Delete all the points

    cout << endl <<  &twentyInts << endl;
    delete[] tenInt;
    delete[] tenInter;
    delete[] elevenInts;
    delete[] twentyInts;

    cout << endl <<  &twentyInts << endl;
    
    //10 Create a print method for vector
    //          Allocate 10 ints +1 print
    //          allocate 11 ints + print
    //          allocate 20 ints + print
    vector<int> v1 {100,102,103,104,105,106,107,108,109};  
    vector<int> v2 {100,102,103,104,105,106,107,108,109,110};  
    vector<int> v3 {100,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,116,117,118,119};  

    print_vector(cout, v1);
    print_vector(cout, v2);
    print_vector(cout, v3);

    

    return 0;
}
