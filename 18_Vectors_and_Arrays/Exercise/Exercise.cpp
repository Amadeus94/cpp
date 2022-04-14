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
	int length = 0;
	for(int i=0; *ch+i!='\0'; i++){
		length++;	
	}
	char* c = nullptr;

	cout << "length of string is: " << length;

	return   c;




}
 
int main(){
	char* c = new char[]{"hello"};
	strdup(c);
}



