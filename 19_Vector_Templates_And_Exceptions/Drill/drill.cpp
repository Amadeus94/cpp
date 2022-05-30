#include <vector>
#include <iostream> 
#include <string>
using namespace std;
// 01. Define template<typename T> struct S {T val;} 
// 02. Add a constructor, so that you can initialize with a T
template<typename T> 
struct S{

	S(T value){
		val=value;
	}

	//05: add a function template get() that returns a reference to val
	//	<- Not sure if should add a template for this 
	T& get();
	const T& get() const ;

	void set(T value);
	

	//operator=(const T&);   <<- No idea why not working to declare. Is it not possible to declare operator overload?
	S& operator=(const T&);   // Was onlyu msissing a void - since this is basically a function 

	void read_val(T& v);



//07: make val private
private:
	T val;
	
};

//14: ovverload << and >> opertator for vector<T>s
//// for both input and output use a 
//			{val,val,val}  - format
//That will allow read_val() to also handle the S<verctor<int>> variable
istream& operator>>(istream& is, S<vector<int>>& v){

	char ch1;		//{
	int	ch2; 		// item
	char ch3;		// ,	
	char ch4;		// }

	cin >> ch1;
	if(ch1 !='{') {
		cout << "error";
	   	return is;
	}

	while(cin >> ch2 >> ch3) {
		if(ch3=='}') 
			break;
		v.get().push_back(ch2);
	}
		
		//v.read_val(v.get().pushback(ch2))	;
//	j	while(cin>>ch1>>ch2>>ch3);

	return is;

}

void operator<<(ostream& os, S<vector<int>> vi){
	vector<int> v = vi.get();
	cout << '{';
	for(int i = 0; i<v.size(); i++){
		cout << v.at(i);
		if(i!=v.size()-1)
			cout << ',' ;
	}
	cout << '}';
}





//06: Put the deifntion of get() outside the class
template<typename T> 
T& S<T>::get() {
		return val;
}

//11: Provide a const and non-const version of get()
template<typename T>
const T& S<T>::get() const{
	return this->val;
}

//09:Add a set() function template so that you can change val
template<typename T> 
void S<T>::set(T value){
	//val=value;		// use this-> instead?
	this->val=value;		// use this-> instead?
}

//10: replace set() with an S<T>::operator=(const T&). Hint: much simpler than $19.2.5
//template<typename T> 
//void S<T>::operator=(const T& value){
//	this->val=value;		// use this-> instead?
//}

//10 - version02: 
//replace set() with an S<T>::operator=(const T&). Hint: much simpler than $19.2.5
// 19.2.5
//vector& vector::operator=(const vector& a)
//{
//	if(this==&a) return *this; /// self-assignment, no work needed 
//
//	if(a.sz <=space) {
//		for(int i= 0; i<a.sz; ++i) elem[i] = a.elem [i]; // copy elements
//		sz = a.sz;
//		return *this;
//	}
//
//	double* p=new double[a.sz]; 		// allocate new space
//	for(int i = 0; i<.a.sz; ++i)  
//		p[i]=a.elem[i];					// copy elements
//
//	delete[elem] elem;	// deallocate old space
//	space = sz = a.sz;
//	elem = p;
//	return *this;
//
//	
//}

//template<typename T> 
//void S<T>::operator=(const T& value){
//	if(this==&value) // self-assignment - no work needed
//		return;
//
//	this->val=value;		// use this-> instead?
//}


// Should be S& instead of void

template<typename T>
S<T>& S<T>::operator=(const T& value){
	this->val=value;

	return *this;
}


// 12: define a function template<typename t> T& read_val(T& v)  that reads from cin into v
template<typename T>
void S<T>::read_val(T& v){
	cin >> v;
};


int main(){
// 03. Define variables of types:
// 			S<int>, S<char>, S<double>, S<string>, S<vector<int>> 
	S<int> i(10);
	S<char> ch('h');
	S<double> dbl(12.0); 
	S<string> str("hello world");


	vector<int> vi;
	S<vector<int>> v(vi); 
	///S<vector<int>> v(vector<int>{1,2,3,4}); // is this memory leak aber was? // no items stored appearantly


	//			version 01			//
	//04 Read those values and print them 
//	cout << i.val  << endl << 
//			ch.val << endl <<
//			dbl.val << endl <<
//			str.val << endl << endl;
//			

//	for(auto item : v.val)
//		cout << item << endl;


	//			version 02					//
	//			08: Do 4 again using get()	//
	//04 Read those values and print them 
//	cout << i.get()  << endl << 
//			ch.get() << endl <<
//			dbl.get() << endl <<
//			str.get() << endl << endl;
//			
//
//	for(auto item : v.get())
//		cout << item << endl;
//

	//13: use read_val() to read into each fo the variables from 3 except the S<zvector<int>> variable
	
//	ch.read_val(ch.get());
//	cout << ch.get() << endl;
//
//	i.read_val(i.get());
//	cout << i.get() << endl ;
//
//	dbl.read_val(dbl.get());
//	cout << dbl.get() << endl;
//
//	str.read_val(str.get());
//	cout << str.get() << endl;
//

//	str.read_val(str.get());
//	cout << str.get() << endl;



	// 14 Test
	cin >> v;

//	for(auto item : v.get())
//		cout << item << endl;

cout << v;
}
