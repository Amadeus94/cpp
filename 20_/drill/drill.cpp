#include <vector>
#include <array>
#include <iostream>
#include <list>
using namespace std;


//6 
template <typename Iter1, typename Iter2>
	// requires Input_iterator<Iter1>() && Output:iterator<Iter2>()
Iter2 copy(Iter1 f1, Iter1 e1, Iter2 f2){
	if(f1==e1) // empty
		return f2;
	while(f1!=e1){
		*f2=*f1;
		f1++; f2++;
		 }
	return f2;
}

int main(){
	//1,2,3,4,5,6
	array<int,10> arr {1,2,3,4,5,6,7,8,9};
	vector<int> v{1,2,3,4,5,6,7,8,9};
	list<int> li{1,2,3,4,5,6,7,8,9};

	array<int, 10> arr02 ;
	vector<int> v02;  
	list<int> li02 ;

	//7 
	::copy(li.begin(), li.end(), arr02.begin());
	::copy(v.begin(), v.end(),li02.begin());

	for(auto item :  arr02)
		cout << item << endl;

	//int arr02[]  = {1,2,3,4,5,6,7,8,9};
	//vector<int> v02 = v;
	//list<int> li02 = li;

//	for(int i = 0; i<10; i++){
//		arr[i] *=2;
//	}
//
//	for(auto i=v.begin();i!=v.end();i++) {
//		(*i)*=3;
//	}
//
//	for(auto i=li.begin();i!=li.end();i++) {
//		(*i)*=5;
//	}
//
//	for(auto item : v)
//		cout << item << endl;

}
