#include <memory>
#include <string>
#include <iostream>
using namespace std;

template<typename T>
class Unique_ptr{
	public: 
	T* ptr;

	Unique_ptr(){
		ptr = new T();
	}

	~Unique_ptr(){
		delete ptr;
	}

	Unique_ptr operator->(){
		return *ptr;
	}

	Unique_ptr operator*(){
		return *ptr;
	}

	T release(){
		T* outOfScope = ptr;
		ptr= nullptr;
		return *outOfScope; 
	}
};

int main() {
	Unique_ptr<int> ptr; 
	cout <<  ptr.release() << endl ;
}
