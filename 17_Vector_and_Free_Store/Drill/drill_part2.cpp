#include <iostream>
#include <vector>
using namespace std;


ostream& print_array(ostream& os, int* a, int n){
    for(int i=0; i<n; i++){
        os << a[i];
        if(i!= n-1)
            os << ",";
    }
    return os;
}


int main(){

    //1. Allocate an int, initialize it to 7, and assign its address to a variable p1
    int* p1 = new int{7};

    //2. Print out the value of p1 and of the int it points to 
    cout << "The pointer on address " << p1 << " contains the int value " << *p1 << endl;

    //3. Allocate an array of seven ints: initialzie it to 1,2,4,8 etc. 
    int* p2 =  new int[7] {1,2,4,8,16,32,64} ;

    //4. Print out the value of p2 and of the array it points to 
    cout << "The pointer on address " << p2 << " contains the int values:" << endl;
    print_array(cout, p2, 7);
    cout << endl;

    //5. Declare an int* called p3 and initialize it with p2
    int* p3 = p2;

    //6. Assign p1 to p2
    p2 = p1;

    //7 Assign p3 to p2 
    p2 = p3;

    //Print ou tthe values of p1 and p2 of what they are pointing to
    cout << "The pointer on address " << p1 << " contains the int value " << *p1 << endl;
    cout << "The pointer on address " << p2 << " contains the int value " << *p2 << endl;


   delete [] p2;
  delete [] p1;
  //delete [] p3;  Cannot delete this .... I think it would be akin to double dleete pointers ..
  //    IE  needo nly delete one .. but both point to null bnehaviour ... could perhaps just point them after to nullptr
    p1=nullptr;
    p2=nullptr;
    p3=nullptr;

    cout << "hello" << endl;
    
    // This line for some reeason is not printed at  all
    //
    //cout << "The pointer on address " << p2 << " contains the int value " << *p2 << endl;

    //Allocate an array of ten ints ; initialize it to 1,2,4,7 and assign its address to a variable p1

    p1 = new int[10] {1,2,4,8,16,32,64,128,256,512};
    p2 = new int[10];

    for(int i=0; i<10; i++){
        p2[i] = p1[i];
        cout << p2[i] << endl;
    }


    // Do same with vector
    vector<int> v1{1,2,4,8,16,32,64,128,256,512};
    vector<int> v2(10);

for(int i=0; i<v1.size(); i++){
        v2[i] = v1[i];
        cout << v2[i] << endl;
    }



    


    return 0;
}



// Notes
// Assign a to b means:
//  b=a
