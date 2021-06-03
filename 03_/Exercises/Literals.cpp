#include <iostream>
#include <iomanip>
#include <typeinfo>

#include ".\Typeof\typeof_test.cpp"
using namespace std;

// On courtesy of tutorialspoint.com - Article "C++ Constants/Literals"
/* 
 * General on Literals
	Constants refer to fixed values that the program may not alter
		and they are called 'literals'

	Constants can be of any of the basic data types 
		and can be divided into
			Integer Numerals
			Flaoting-Point Numerals
			Characters
			Strings
			Boolean
			...values
	Constants/Literals are treated just like regular variables except their values cannot be modified after their definition
   */



// Defining Constants
// 	two ways: 
// 		using #define preprocessor 
// 		using const keyword

// 		syntax		#define identifier value
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'

int definePreprocsosseor() {
   int area;  
   
   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}

int usingConst() {
	// Best practice to call const with Capital letters:w
	//
   const int  LENGTH = 10;
   const int  WIDTH  = 5;
   const char NEWLINE = '\n';
   int area;  
   
   area = LENGTH * WIDTH;
   cout << area;
   cout << NEWLINE;
   return 0;
}
		

void integer_literal_test(){
	// Integer literal
	// 	Decimal
	// 	Octal
	// 	Hexadecimal
	// 		.. constants

	// A prefix specifies the base or radix: Can be upper or lower doesnt matter
	
	// 0x or 0X for hexadecimal
	0XFeel; // legal		
	// Suffix L or U stands for type // can be upper or lower  doesn't matter
	// 	L = long
	// 	U = unsigned
	cout << "0x or 0X is the prefix for hexadecimal" << endl; 
	cout << "\t 0xFeel equals: " << 0xFeel <<endl; // legal
		// Notice the l or L behind stands for type L
		// 	this means we're creating a hexa decimal of FEE of type Long
		// On the same token you could write ll behind so it would be of type long long
	cout << "\t 0XFeel equals: " << 0XFeel <<endl; // legal
	cout << "\t 0XFEEL equals: " << 0XFEEL <<endl; // legal
		// We calculate Hexadecimal by; F = 15 -- last number --- 0 = 0
	cout << "\t 0xF equals: " << 0xF << endl;
	cout << "It is calculated by putting into 16th power :  ABC = C*(16^0) + B*(16^1) + A*(16^2)" << endl; 
	cout << "It is calculated by putting into 16th power :  ABC = " << 0xC << "*(16^0) + " << 0xB<< "*(16^1) + " << 0xA << "*(16^2)"; 



	215u; // legal 215 unsigned int
	215U; // legal 

	/*
	 * 
	 *
	 Similarly, the suffix U (or u ) forces a constant to be unsigned . ... If a constant has both L and U suffixes, ( LU or UL ), its data type will be unsigned long int . If a constant has the LL , its data type will be long long . If a constant has the ULL , its data type will be unsigned long long .*/
// Doesn't matter which type comes first:
	0x2421lu;
	0x2421ul; // both are of unsigned long int 	


	//////////////////////////////////////////////////////
	//Octals .. Prefix 0  ie 07  =  8 
	//			 08 =  error... there is no 8 in octal
	cout << "octal 07 :  " << 07; // prints 7 


////CAN't repeat a suffix
//	0x24auu  --- error... can't repeat suffix.. can't say it is twice of type unsigned int	
	


// Other examples of various types of integer literals

85; // decimal ... - I thought this would be of type int	
		// the documentation is wrong: this is a int
0213; // octal 
0x4b; // hexadecimal; 
325.5; // double
10.5f; // float literal
10.; // double  -- tested and verified
30u; // unsigned int;
30; //long;
30ul; // unsignedlong int

// binary literal 0b prefix 0b10101 
0b10101001;
10ull;


// Test of types -- it returns a string of the type... The declaration is in the included file 
cout << type_name<decltype(85.)>() << '\n'; // prints double 
cout << type_name<decltype(0213)>() << '\n'; // prints int
cout << type_name<decltype(30ul)>() << '\n'; // prints unsigned long
cout << type_name<decltype(30lu)>() << '\n'; // prints unsigned long
cout << type_name<decltype(30u)>() << '\n'; // prints int
cout << type_name<decltype(30ull)>() << '\n'; // prints unsigned long long 
cout << type_name<decltype(30llu)>() << '\n'; // prints unsigned long long 
cout << type_name<decltype(85.)>() << '\n'; // prints int

int i = 12; 
typeid (i);


}


void floating_point_literals(){

	// A floating-point literal has an
	//	integer part, decimal  point, fractional part and an exponent part
	//Represent floating point  literals by either
	//	decimal form or exponential form
	
	// Decimal form
	// 	Must include the decimal point (.8383), the exponent(e-34), or both
	// Exponential form
	// 	must include integer part, fractional part, or both
	//
	// the signed exponent is introduced by e or E
	
	3.14159; // legal
	3.14159E-5L; // legal 0.0000314159
	cout << 3.14159E-5L << endl;
	cout << setprecision(9) << fixed << 3.14159E-5L << endl;
	cout << setprecision(9) << showpoint<< fixed << 3.14159E-5L << endl;

	/* Illegal
	 510E // illegal - incomplete exponent
	 210f // illegal - no decimal or exponent ... float -- mangler komma eller e-10
	 .e55 // illegal - missing integer or fraction*/ 
}


void boolean_literal(){

	// There are two boolean values in c++ 
	// 	true, false
	// 		
	// You should not consider the value of true equal to 1 
	// 			       	   nor false equal to 0 
	true;
	false;

}

void character_literal(){
	// character literals are enclosed in 'c' 
	// 	if literal begins with L(Uppercase only), it is a wide character literal
	L's';

	// otherwise it is a narrow character literal
	's';
	// A character literal can be either a 
	// 	plain character:  'a'
	// 	escape sequence: '\n''\t' etc.
	// 	universal character: '\u02C0'
		// Unicode
			// Each character has a number from from 0-65,535 
			// Unicode for K :  U+004B
			// can do same as escape sequnece
			// 	\u004B
			// 	k is two down the row ie.  \u006B 
			// 		ie can be found on row 6 on column B ie 11 
			// C++ doesn't use it 'U+0000' characters.. it uses \u instead
	// writing unicode for karl
//	cout << L'U+004B' << L'U+0041' << L'U+0042'<< L'\u004C'; // c++ doesn't support U+0000 syntax.. but \u
	
	cout << L'\u004B' << L'\u0041' << L'\u0042'<< L'\u004C'; // printed 756556676.. lol


	// special characters/Escape sequence 	
	'\t'; // horizontal tab
	'\v'; // vertical tab

	'\a'; // alert or bell ... didn't hear anything
	'\b'; // backspace 
	'\f'; // form feed
	'\r'; // carriage return
	'\000'; /// octal number of one to three digits
	'\00'; 
	'\xAA'; //Hexadecimal number of one  or more digits  

}

int main(){


string test = "Hello \t"  
		"\v"
		"\a alarm\b"
		"\f form feed" // Form feed is a page-breaking ASCII control character. It forces the printer to eject the current page and to continue printing at the top of another. Often, it will also cause a carriage return.
		"carriage return \r"
		// difference between \n & \r 
			// They're different characters. \r is carriage return, and \n is line feed.
			//On "old" printers, \r sent the print head back to the start of the line, and \n advanced the 					paper by one line. Both were therefore necessary to start printing on the next line.
		"\000 octal"
		"\01 octal"
		"\xAA Hexa";



	cout << test;

	test = "Hello\b there" 
	       "\v I just created vertical tab"
       			;	       

	/*
	 *Obviously that's somewhat irrelevant now, although depending on the console you may still be able to use \r to move to the start of the line and overwrite the existing text.

More importantly, Unix tends to use \n as a line separator; Windows tends to use \r\n as a line separator and Macs (up to OS 9) used to use \r as the line separator. (Mac OS X is Unix-y, so uses \n instead; there may be some compatibility situations where \r is used instead though.) 
n C and C++, \n is a concept, \r is a character, and \r\n is (almost always) a portability bug.	

This is a subtle but important point: \n is mapped at compile time to an implementation-defined character value which (in text mode) is then mapped again at run time to the actual character (or sequence of characters) required by the underlying platform to move to the next line.

\n is different than all the other backslash literals because there are two mappings involved. This two-step mapping makes \n significantly different than even \r, which is simply a compile-time mapping to CR (or the most similar control code in whatever the underlying character set is).



*/
	
integer_literal_test();
cout << endl << endl << endl;
floating_point_literals();
cout << endl << endl << endl;
cout << "character literals: " << endl;
character_literal();


// string literals: All are equivalent
"hello, dear";

"hello, \
dear";

"hello, " "d" "ear";
	return 0;
}
