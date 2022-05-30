#include <vector>
#include <iostream>

using namespace  std;

// 02: Write a template function that takes a vector<T> vt and a vector<U> vu as arguments
// 			and returns the sum of all vt[i*vu{i]s 

template<typename T, typename U>
vector<U> addVectorDiff(vector<T> vt, vector<U> vu){
	vector<U> result;

	{
		U sum = 0;
		for(int i=0; i<vu.size(); i++){
				sum = vt.at(i) + vu.at(i);
				result.push_back(sum);
			}
	}
	return result;
}


int main(){
	vector<int> v1 {1,2,3,4};
	vector<double> v2{1.1,2.2,3.3,4.4};

	vector<double> result = addVectorDiff(v1,v2);

	for(auto item : result)
		cout << item << endl;
}
