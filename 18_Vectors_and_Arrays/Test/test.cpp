#include <iostream>
using namespace std;

class dog{
    public:
    int j=3;
    dog(int i){
        j=i;
    }
        
};
int main(){
    //int var[10] = {1,2,3,4};

    //for(int i=0; i<10; i++)
    //    std::cout <<  var[i] << std::endl;

    // Asssignment
    dog i(2);       // 0x61fe1c
    dog j = i;      // 0x61fe18

    // not the same

    cout << &i << endl;
    cout << &j << endl;

    // But what about the internals?
    cout << &(i.j) << endl;
    cout << &(j.j) << endl;

    
}
