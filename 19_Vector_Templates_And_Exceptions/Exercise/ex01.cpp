// 01: Wrtie a template function f()
// 	that adds the elements of one vector<T> to the elements of another
// 		for example:  fv1, v2) should do v1[i]+v2[i] for each element of v1

#include <vector>
#include <iostream>
using namespace std;

template<typename T> 
vector<T> addVector(vector<T> v1, vector<T> v2){
	vector<T> result;

	{

		T sum = 0; // Weirdly enough -- this is wrong if write auto instead
		for(int i=0; i<v1.size();i++){
			sum = v1.at(i)+v2.at(i); 
			result.push_back(sum);
		}	
	}
	return result;
}

int main(){
	vector<int> v1{1,2,3,4};
	vector<int> v2{2,3,4,5};

	vector<double> v3{1,2,3,4};
	vector<double> v4{2.2,3.3,4.4,5.5};


	vector<int> intVector = addVector(v1, v2);
	vector<double> doubleVector = addVector(v3,v4);

	for(auto item : intVector)
		cout << item << endl;

	cout <<endl << endl;

	for(auto item : doubleVector)
		cout << item << endl;
}

