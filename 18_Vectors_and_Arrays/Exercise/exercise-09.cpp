#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

// Create a program that tells the order in which
// 	static storage, the stack, free store are laid out in memory.
// 		In which way does stack grow towards higher or lower addresses?
//		In an array on the fre store, are elements with higher indices allocated at higher or lower addresses?


// check stack grows up or down
//		https://www.geeksforgeeks.org/c-program-find-direction-growth-stack/   
void fun(int *main_local_addr)
{
	int fun_local;
	if (main_local_addr < &fun_local)
		printf("Stack grows upward\n");
	else
		printf("Stack grows downward\n");
}

int main(){

	// Notice this illustration is contrary to the Memory Layout of C program where stack is at the top and grows down...
	cout << "The structure in memory in chapter 17.4 is: " <<endl << endl;
	cout << "1: Code Segment"<< endl;
	cout << "2: Static Storage"<< endl;
	cout << "3: Free Store"<< endl;
	cout << "4: Stack"<< endl;

	
	cout << "===========================================" << endl;
	cout << "In which way direction does the stack grow?" << endl;
	cout << "===========================================" << endl;

	// fun's local variable
	// The idea is to do following :
	// 1) Make a local variable in main.
	// 2) Write another function fun() with its own local variable.
	// 3) Make a call to fun() from main. Compare addresses of two local variable. If address of fun()’s local variable is more than main’s local variable, then stack grows upward (i.e., addresses increase)
	int main_local;
    fun(&main_local);

//		My Implementation: 
//		char word[12]= "hello";
//		cout << "consider the char arary with " << word << endl;
//	
//		// int large enough to contain a memory addres from the stdint library 
//		uintptr_t address01 = reinterpret_cast<uintptr_t>(word+0); 
//		uintptr_t address02 = reinterpret_cast<uintptr_t>(word+1);
//	
//	
//		cout << "address 1 ie h : " << address01 << endl;
//		cout << "address 2 ie e : " << address02 << endl;
//		cout << "which means that the stack grows ";
//		cout << (address01>address02? "down" : "up") << " toward " << (address01>address02? "lower" : "higher") << " addresses"  << endl ;

	cout << "======================================================" << endl;
	cout << "In which way direction does the free store(heap) grow?" << endl;
	cout << "======================================================" << endl;

	char *i= new char[10];

	uintptr_t address03 = reinterpret_cast<uintptr_t>(i+0); 
	uintptr_t address04 = reinterpret_cast<uintptr_t>(i+1);

	cout << "The heap grows ";
	cout << (address03>address04? "down" : "up") << " toward " << (address03>address04? "lower" : "higher") << " addresses"  ;
}
