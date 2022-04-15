#include <iostream>
using namespace std;

//Exercise 01
//	Write a fucntion char* strdup(Const char*) 
//		that copies a C-Styele string into memory it allocates on the free store
//	DO NOT
//		Use any standard library functions 
//		Use subscription[] 
//	Use only the dereference operator * instead
char* strdup(const char* ch){
	// find length 
	int length = 0;

	for(const char* ch2=ch; *ch2; ch2++){ // as long as ch2 != 0  .. \0
		length++;
	}

	//allocate to heap
	char *s= new char[length+1]; // add 1 to length because of \0
	// copy values
	for(int i=0; i<length+1;i++){
		*(s+i)= *(ch+i);
	}
	*(s+length) = '\0';

	return s;
}
 
int main(){

	cout << "starting.... \n";

	const char* p = "hello";

	char* pointer = strdup(p);

	cout << pointer;  // standard output can print it 
}



