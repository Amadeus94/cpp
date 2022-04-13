#include <iostream>
#include <vector>
using namespace std;

void size(char ch, int i, int* p){
    cout << "size: " << sizeof(char) << " : " << sizeof(ch);
    cout << "size: " << sizeof(int) << " : " << sizeof(i);
    cout << "size: " << sizeof(int*) << " : " << sizeof(p);
};

int main(){
   char ch = 'a';
   int i = 12; 
   int* p = &i; 

  size(ch,i,p);

 cout <<  sizeof(bool);
  cout << sizeof(double);


  cout << endl;

  vector<int> v1(1);
  vector<int> v2(10);
  vector<int> v3(100);
  vector<int> v4(1000);

    cout << 
           sizeof(v1) << endl 
<<           sizeof(v2) << endl 
<<           sizeof(v3) << endl 
<<           sizeof(v4) << endl ;
}


