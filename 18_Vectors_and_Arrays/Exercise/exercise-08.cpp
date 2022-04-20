#include <string>
#include <algorithm>
#include  <iostream>
#include <cstring>

using namespace std;


//String implementation:
bool is_palindrome(const string& s){
	string reverseString = ""; 

	for(auto it = s.rbegin(); it!=s.rend(); ++it)
	{
	reverseString.push_back(*it);
	}

	bool result = s==reverseString ? true:false;

	return result;
}

//array implementation
bool is_palindrome(const char s[], int n){

	char reverseString[n];

	// avoid copying \0
	int j = n-2;
	for(int i=0; i<n-1; i++){
		reverseString[j] = s[i];
		j--;
	}
	reverseString[n-1] = '\0';



	// avoid comparing \0 terminator
	j=n-2;
	bool isIdentical;
	for(int i=0; i<n; i++){
		if(reverseString[i] != s[i])
				return false;
	}	
	return true;
}


//pointer
bool is_palindrome(const char* first, const char* last){
	

	//Count the length to allocate
	int n = 0;
	while(*(first+n) !='\0' )
		n++;
	n++; // add \'0
	char* reverseString = new char[n]; 	


	// avoid copying \0
	int j = n-2;
	for(int i=0; i<n-1; i++){
	*(reverseString+j) = *(first+i);
		j--;
	}
	reverseString[n-1] = '\0';



	// avoid comparing \0 terminator
	j=n-2;
	bool isIdentical;
	for(int i=0; i<n; i++){
		if(reverseString[i] != first[i])
				return false;
	}	
	return true;

//
//
    return true;
}

int main(){
	
	////test string
	//string s1 = "anna";
	//string s2 = "ana";
	//string s3 = "ans";

	//cout << s1 << "is a palindrome: " << is_palindrome(s1) << endl ;
	//cout << s2 << "is a palindrome: " << is_palindrome(s2) << endl ;
	//cout << s3 << "is a palindrome: " << is_palindrome(s3) << endl ;

	//test char Array
//	char s1[] = "anna";
//	char s2[] = "ana";
//	char s3[] = "ans";
//
//	is_palindrome(s3,4);
//
//	cout << s1 << " is a palindrome: " << is_palindrome(s1,5) << endl << endl ;
//	                
//	cout << s2 << " is a palindrome: " << is_palindrome(s2,4) << endl << endl ;
//	cout << s3 << " is a palindrome: " << is_palindrome(s3,4) << endl << endl ;


	//test char pointer 
	const char *s1 = "anna\0";
	const char *s2 = "ana\0";
	const char *s3 = "ans\0";



	cout << s1 << " is a palindrome: " << is_palindrome(s1,s1+3) << endl << endl ;
	                
	cout << s2 << " is a palindrome: " << is_palindrome(s2,s2+2) << endl << endl ;
	cout << s3 << " is a palindrome: " << is_palindrome(s3,s2+2) << endl << endl ;





	return 1;
}
