#include  "..\Bjarnes_Standard_Header\std_lib_facilities.h"


//no such file : compile error 
//#include  "..\Bjanes_Standard_Header\std_lib_facilities.h"

// if wrote integer instead of int : compile error: /-> 'integer' does not name a type
int main() // C++ programs start by excecuting the function main
{
	cout << "Hello, World!\n"; 
	// cout << 'Hello, World!\n'; //  Using '' instead of "" : Compiler error : --> character constant too long for its type  
	//cout < "Hello, World!\n"; // Compile error : -->  no match for operator 'operator<'  
	keep_window_open();
//	keep_window_open(); // forgot ";" -> compile error: 
  
	//keep_window_open(), // Compile error -> expected primary expression before "return"
	// Errors
	//	COUT // -> Gives error COUT was not declared
	// 	cout << "Hello, World!\n;  //->.. missing " at end ... -> Compile error: Expected primary-expression before "return" 
	return 0;
}

