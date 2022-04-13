#include <vector>
#include <string>
#include <iostream>
using namespace std;


vector<int> gv{1,2,4,8,16,32,64,128,254, 512};

void f(vector<int> vv){

   vector<int> lv(vv.size()); 

   for(int i=0; i<vv.size();i++){
       lv.at(i) = vv.at(i);

       cout << lv.at(i) << (i!=vv.size()-1 ? "," : "");  
   }

   vector<int> lv2{lv};
   cout << endl << endl;

    for(int i=0; i<vv.size();i++){
       cout << lv2.at(i) << (i!=vv.size()-1 ? "," : "");  
   }
}

int factorial(int n){
    int result=1;

    for(int i=n; i>0;i--){
        result*=i;
    }
    return result;
}

int main(){

    f(gv);

    vector<int> vv{
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

    f(vv);



}
