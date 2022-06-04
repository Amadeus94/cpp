#include <memory>
using namespace std;

template<typename T>
class Allocator{
public:
	//..
	T* allocate(int n){ // allocate space for n objects of type T
		// malloc function returns a pointer to the allocated memory, or NULL if the request fails.
		//return malloc(n*sizeof(T*));   -- my method
		return (T*) malloc(sizeof(T*)*n);  // should always contain cast
	}

	void deallocate(T* p, int n){
		for(int i=0; i<n; i++){
			destroy(p[i]);
		}
	} //deallocate n objects of type T starting at p

	void construct(T* p, const T& v){ // construct a T with the value v in p
		*p=copy(v);
	}

	void destroy(T* p){ //Destroy the T in P
		free(p);
	}
};

struct out_of_range{
};

template<typename T, typename A=Allocator<T>>
class vector{
	T& at(int n); // checked access
	const T& at(int n) const;  // checked access    - First const makes the  value pointed by the pointer immutable    and the second means it is a constant pointer 
												// const char * is a pointer to a constant char,
												// while char * const is a pointer to a char


	T& operator[](int n); 			//Unchecked Access
	const T& operator[](int n) const ; 			//Unchecked Access

};

template<typename T, typename A>
T& vector<T,A>::at(int n){
	if(n<0 || sz<=n) 
		throw out_of_range();
	return elem[n]
}



