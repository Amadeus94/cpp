#include <string>
#include <iostream>

using namespace std;


int stringLength(const char* s)
{
	int length=0;

	while(*(s+length))
		length++;

	return length;

}

//Exercise 07
//	Modify cat_dot
//		to take C-style strings as arguments, and return a free-store allocated C-style string as the result
//			Do not use library functiosn or types in the implementation
//		Test these functions with several strings
//		Be sure to free (using delete) all the memory you allocated from free store(using new) 
//
//		Compare the effort from exercise 05-06 vs 07
char* cat_dot(const char* s1, const char* s2, const char* separator){

	//find length of each string without '\0'
	int length_s1 = stringLength(s1);
	int length_s2 = stringLength(s2);
	int length_seperator = stringLength(separator);

	int sumOfStringLengths = length_s1 + length_s2 + length_seperator; 

	// Allocate a on heap
	char* result = new char[sumOfStringLengths+1]; 

	// Add s1
	for(int i=0; i< length_s1; i++){
		*(result+i)= *(s1+i);
	}
	// Add add Seperator 
	for(int i=0; i+length_s1<length_s1+length_seperator ; i++){
		*(		result
				+length_s1
				+i
				)= *(separator+i);
	}

	
	// add  s2
	for(int i=0; i<sumOfStringLengths; i++){
		*(result
				+length_s1
				+length_seperator
				+i)= *(s2+i);
	}


	// add '\0'
	*(result+sumOfStringLengths)='\0';

	
	return result;
}

int main(){
	const char* s1 = "Niels";
	const char* s2 = "Bohr";
	const char* separator= "_";

	char* result = cat_dot(s1,s2,separator);

	cout << endl <<result << endl;

	delete result;
	//delete s1; // error - ie this is on stack
}
