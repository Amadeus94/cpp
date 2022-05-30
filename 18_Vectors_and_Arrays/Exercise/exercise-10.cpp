#include <string>
#include  <iostream>
#include <cstring>

using namespace std;


//array implementation
bool is_palindrome(const char s[], int n){
    int first =0;
    int last = n-1;

    while(first<last){ // we haven't reached the middle 
        if(s[first]!=s[last])
            return false;
        ++first;
        --last;
    }
    return true;
}

// Read characters into the array
//  This is a way to do it safely (ie withotu risk of overflowing the array) 

istream& read_word(istream& is, char* buffer, int max) {
	if(max>128) {
		cout << endl << "Error -- Too large " << endl;
		return is;
	}


    // read at most max-1 characters from is into buffer
    is.width(max); // read at most max-1 characters in the next >>
                    // ie Width of the next formatted element to insert.
                    //      if anna then width = 4 then will read all 4 


    is >> buffer;   // read whitespace-terminated word,
                    // add zero after the last charactger read into buffer


    // More info:
    //  setting the istream's width appropriately prevents buffer overflow fopr the next >> operation
    //          However, it also means that we don't know if the read terminated by
    //              whitespace or by buffer being full (  so that we need to read mroe characters)
    //
    //ð
    return is;

}



int main(){

    // test array implementation 
    constexpr int max = 128;

	// exercise10 
	// 	fix it to deal with long strongs by: 
	// 		a) report if an input string was too long 
	// 		b) allowing an arbitrarily long string 		
    for(char s[max]; read_word(cin,s, max);){
            cout << s << " is "; 
            if(!is_palindrome(s,strlen(s))) 
                cout << "not ";
           cout << "a palindrome \n"; 
    }
}
