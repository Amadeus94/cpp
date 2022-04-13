#include <string>
#include  <iostream>
#include <cstring>

using namespace std;


//String implementation:
bool is_palindrome(const string& s){
    int first =0;
    int last = s.length()-1;

    while(first<last){
        if(s[first]!=s[last])
            return false;
        ++first;
        --last;
    }
    return true;
}

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


//pointer implementation (Instead of using indices to identify characters - we could use pointers
//bool is_palindrome(const char* first, const char* last){
//    while(first<last){
//        if(*first!= *last)
//            return false;
//        ++first;
//        --last;
//    }
//    return true;
//}

// another impl of pointer palindrome
bool is_palindrome(const char* first, const char* last){
    if(first<last){
        if(*first!=*last)
            return false;
        return is_palindrome(first+1, last-1); // recursive
    }
    return true;
}

int main(){

    // test string implementation 
//    for(string s; cin>> s;) {
//        cout << s << " is";
//        if(!is_palindrome(s)) 
//            cout << " not";
//        cout << " a palindrome\n"; 
//    }
//
    // test array implementation 
     
//    constexpr int max = 128;
//
//    for(char s[max]; read_word(cin,s, max);){
//            cout << s << " is "; 
//            if(!is_palindrome(s,strlen(s))) 
//                cout << "not ";
//           cout << "a palindrome \n"; 
//    }

    //pointer impl
    const int max = 128;
    for(char s[max]; read_word(cin,s,max);){
        cout << s << " is";
        if(!is_palindrome(&s[0], &s[strlen(s)-1]))
            cout << " not";
        cout << " a palindrome\n";
    }
}
