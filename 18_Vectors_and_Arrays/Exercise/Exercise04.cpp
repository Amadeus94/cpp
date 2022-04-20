#include <iostream>
using namespace std;



// Stack vs Heap 
//Example:                       Allocation Type:     Read/Write:    Storage Location:
//================================================================================
//const char* str1 = "Stack";    // Static               Read-only      Code segment
//char* str2 = "Stack";          // Static               Read-only      Code segment
//char* str3 = malloc(...);      // Dynamic              Read-write     Heap
//char str4[] = "Stack";         // Static               Read-write     Stack
//char strGlobal[10] = "Global";// Static               Read-write     Data Segment (R/W)



// Anything written that is allocated on the stack will be freed once a functiongoes out of scope
// 		Anything on the heap  must be explicitlyu freed
// 	Ie using the new is the heap  
// 		anything else is the stack


//Exercise04
//	Redesign and implement the functions so that they take another argument giving the maximum number of elements allowed in argument strings.
//		Then test with Correct C-style strings and "Bad" strings


char* strdup(const char* ch, int max){
	// find length 
	int length = 0;

	for(const char* ch2=ch; *ch2; ch2++){ // as long as ch2 != 0  .. \0
		length++;
	}

	if(length >max) {
		cout << "strdup() only allows " << max << "number of characters" << endl;
		return nullptr;
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


const char* findx(const char* s, const char* x, int max) {
	// find length of substring x
	int subStringLength = 0;

	for(int i=0;*(x+i)!='\0' ;  i++){ // as long as ch2 != 0  .. \0
		subStringLength++;
	}


	int length =0;
	int index =0;

	for(int i=0; length<subStringLength; i++){
//		cout << endl <<  *(s+i) <<"\t" <<  *(x+length)<< (*(s+i)==*(x+length));
		if(*(s+i)==*(x+length)){
			length++;
			index=i;
			continue;
		}
		length=0;
	}
	if(length >max) {
		cout << "findx() only allows " << max << "number of characters" << endl;
		return nullptr;
	}

	cout << endl;
	cout << "subStringLength: " << subStringLength << endl;
	cout << "length: " << length << endl;
	cout << "index: " << index << endl;


	const char* ptrs = s+(index-length+1);

	return ptrs;
}



int strcmp(const char* s1, const char* s2, int max){

	int length = 0;
	while(true){
		if(*(s1)>*(s2))
			return -1;
		if(*(s1)<*(s2))
			return 1;
		if(*s1=='\0' || *s2=='\0')
			break;
		s1++; s2++;
		length++;

   		if(length >max) {
		cout << "strcmp() only allows " << max << "number of characters" << endl;
			return -99;
	}


	}


	return 0;
}

int main(){

	cout << "starting.... \n";

	const char* cp1 = "hello";
	const char* cp2 = "hel";


	//strdup
	cout << "=============	strdup() =============" << endl;
	char* pointer1 = strdup(cp1, 10); // ok
	char* pointer2 = strdup(cp1, 4); // error .. "only allows 4"

	cout << endl << pointer1;  // standard output can print it 
	//cout << endl << pointer2;  // standard output can print it 


	// findx()
	//
	
	cout << endl << endl << "=============	findx() =============" << endl;
	const char* pointer3 = findx(cp1,cp2,10); //  OK : 
	const char* pointer4 = findx(cp1,cp2,2); // error : only allows 2 numebr of charcters
	cout <<  endl << pointer3; 
//	cout <<  endl << pointer4 << endl; 



	cout << endl << endl << "=============	strcmp() =============" << endl;


	int result1 = strcmp(cp1, cp2, 10); //ok
	int result2 = strcmp(cp1, cp2, 2); // error - return -99 instead

	cout  << result1 << endl;
	cout  << result2 << endl;

}
