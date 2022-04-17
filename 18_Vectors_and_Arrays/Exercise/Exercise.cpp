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

//Ex02
//	char* findx(const char* s, const char* x) 
//		finds the first occurrence of the C-style string x in s 
//
//	Use only the dereferencing operator*
 

const char* findx(const char* s, const char* x) {
	// find length of substring x
	int subStringLength = 0;

	for(int i=0;*(x+i)!='\0' ;  i++){ // as long as ch2 != 0  .. \0
		subStringLength++;
	}


	int length =0;
	int index =0;

	for(int i=0; length<subStringLength; i++){
		cout << endl <<  *(s+i) <<"\t" <<  *(x+length)<< (*(s+i)==*(x+length));
		if(*(s+i)==*(x+length)){
			length++;
			index=i;
			continue;
		}
		length=0;
	}

	cout << endl;
	cout << "subStringLength: " << subStringLength << endl;
	cout << "length: " << length << endl;
	cout << "index: " << index << endl;


	const char* ptrs = s+(index-length+1);

	return ptrs;
}



//Write a function int strcmp/(const char* s1, const char* s2)
//	That compares C-style strings
//		return 
//			negative nmumber if s1 is lexigraphically before s2
//			0 if s1 equals s2
//			positive number if s1 is lexigraphicaloly after s2
//
//  		This is slightly confusing. 
//  			Notice that stringA.compareTo( stringB ) returns a negative integer when stringA and stringB are in the correct order.
//  			
//  		Lexigraphically before: a.compare(b) ... a is lexigraphically before b, and therefore return negative
//  		.... to be continued 
//  			
int strcmp(const char* s1, const char* s2){

	while(true){
		if(*(s1)>*(s2))
			return -1;
		if(*(s1)<*(s2))
			return 1;
		if(*s1=='\0' || *s2=='\0')
			break;
		s1++; s2++;
	}


//	cout << *s1 << endl;
//	cout << *s2 << endl; 
//	while(*s1==*s2){
//    	if(*s1<*s2){
//			return -1;	
//		}
//    	if(*s1>*s2){
//			return 1;	
//		}
//		s1++;
//		s2++;
//
//		cout << *s1 << endl;
//		cout << *s1 << endl;
//	}	
//	cout << endl << endl;
//
//	if(*s1=='\0' && *s2!='\0') 
//		return 1;
//	if(*s2=='\0' && *s1!='\0') 
//		return -1;
//
	return 0;
}

int main(){

//	cout << "starting.... \n";
//
//	const char* p = "hello";
//
//	char* pointer = strdup(p);
//
//	cout << pointer;  // standard output can print it 

	//ex02
	const char* p1 = "hello";		
	const char* p2 = "hel";		

//	const char* p3 = findx(p1,p2);

	//cout << p3; 

	//ex03

	int result = strcmp(p1, p2);

	cout << "==============	Exercise 03	=========================" << endl;
	cout << result << endl;
}
