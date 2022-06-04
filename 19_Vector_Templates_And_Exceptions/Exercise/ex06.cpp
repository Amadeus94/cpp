#include <iostream> 
#include <vector>
#include <string>

using namespace std;



/*
 * Repeat the previous exercise, but with a class Number<T>, where T can be any numeric type
 * 	Try adding % to Number and see what happens you try to to use % for Number<double> and Number<int>
 */
template<typename T>
class Number{
public:
	Number(T value){val=value;};

	void setValue(T value){val=value;};
	T getValue() const {return val;};			//diff of const?

	// copy assignment
	Number& operator=(const Number& other)
	{
		//Guard self assignment
		if(this == &other)
			return *this;
		this->val= other.val;

		// When its of vector etc ie heap use this: https://en.cppreference.com/w/cpp/language/operators
		
		return *this;
	}

	


private:
	T val;
};

// Binary Operator 
	// 	Typically implemented as non-.emembers to maintain symmetry
	// 		For example when adding a complex number and an integer.  
	// 			If operator+ is a member function of the complex type, then only complex + integer would compile, and not  integer + complex 
	//
	template<typename T>
	Number<T>& operator+(Number<T>& lhs, const Number<T> rhs){ 
		lhs.setValue( lhs.getValue() + rhs.getValue());
		return lhs;
	}


	template<typename T>
	Number<T>& operator-(Number<T>& lhs, const Number<T> rhs){ 
		lhs.setValue( lhs.getValue() - rhs.getValue());
		return lhs;
	}

	template<typename T>
	Number<T>& operator*(Number<T>& lhs, const Number<T> rhs){ 
		lhs.setValue( lhs.getValue() * rhs.getValue());
		return lhs;
	}

	template<typename T>
	Number<T>& operator/(Number<T>& lhs, const Number<T> rhs){ 
		lhs.setValue( lhs.getValue() / rhs.getValue());
		return lhs;
	}



	template<typename T>
	ostream& operator <<(ostream& out, const Number<T>& f){
		return out << "Number value is: " << f.getValue() << endl;
	}

	template<typename T>
	Number<T>& operator%(Number<T>& lhs, const Number<T> rhs){ 
		lhs.setValue( lhs.getValue() % rhs.getValue());
		return lhs;
	}


//ex07

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
	Number<double> i1(11);
	Number<int> i2(5);
//
//	cout << i1;
//
//	i1.setValue(3);
//
//	cout << i1;
//	i1.setValue(1); // reset value 
//
//	i1= i2; 
//	cout << i1;
//	i1.setValue(1); // reset value 
//

//	cout << i1%i2;




	//ex07
	vector<Number<double>> v1 {1,2,3,4};
	vector<Number<double>> v2{1.1,2.2,3.3,4.4};

	vector<Number<double>> result = addVectorDiff(v1,v2);

	for(auto item : result)
		cout << item << endl;

	
}
