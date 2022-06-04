#include <iostream> 
#include <vector>
#include <string>

using namespace std;

/*
 * Define a class INT 
 * 	having a single membner of class int.
 * 	Define constructor, assignment, and operators +*-/ 
 */


class Int{
public:
	Int(int value){val=value;};

	void setValue(int value){val=value;};
	int getValue() const {return val;};			//diff of const?

	// copy assignment
	Int& operator=(const Int& other)
	{
		//Guard self assignment
		if(this == &other)
			return *this;
		this->val= other.val;

		// When its of vector etc ie heap use this: https://en.cppreference.com/w/cpp/language/operators
		
		return *this;
	}

	


private:
	int val;
};

// Binary Operator 
	// 	Typically implemented as non-.emembers to maintain symmetry
	// 		For example when adding a complex number and an integer.  
	// 			If operator+ is a member function of the complex type, then only complex + integer would compile, and not  integer + complex 
	//
	Int& operator+(Int& lhs, const Int rhs){ 
		lhs.setValue( lhs.getValue() + rhs.getValue());
		return lhs;
	}

	Int& operator-(Int& lhs, const Int rhs){ 
		lhs.setValue( lhs.getValue() - rhs.getValue());
		return lhs;
	}

	Int& operator*(Int& lhs, const Int rhs){ 
		lhs.setValue( lhs.getValue() * rhs.getValue());
		return lhs;
	}

	Int& operator/(Int& lhs, const Int rhs){ 
		lhs.setValue( lhs.getValue() / rhs.getValue());
		return lhs;
	}



ostream& operator <<(ostream& out, const Int& f){
	return out << "Int value is: " << f.getValue() << endl;
}


int main(){
	Int i1(10);
	Int i2(5);

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
	cout << i1/i2;





	
}
