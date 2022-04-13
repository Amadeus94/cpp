#include <vector>
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;


//1. What is the output format of pointer values on your implementation?
void exercise01(){
    int k = 10;
    int* kp = &k;


    cout << kp; // Hexa decimal
                // 0x61fde4
}

//2. How many bytes are there in an:
//      int, double, bool? 
//      4, 8, 1
// Verification
void exercise02(){
    cout << endl << endl;
    cout <<  "sizeof int: \t" << sizeof(int) << endl ;
    cout <<  "sizeof double: \t" << sizeof(double) << endl ;
    cout <<  "sizeof bool: \t" << sizeof(bool) << endl ;
    cout << endl << endl;
}

//3. Write a function, void to_lower(char* s),
//      that replaces all uppercase characters in the C-style string s with their lowercase equivalents
void to_lower(char* s){
    for(int i=i;s[i]!='\0';i++){
       s[i] =  tolower(s[i]);
    }
}


//4. Write a function char* strdup(const char*) 
//      That copies a C-style string  into memory it allocates on the free store
//              Do not use any standard library functions
char* strdup(const char* c) {
    // find size 
    int length = 0;
    for(int i=0; c[i] != '\0'; i++){
        length++;
        cout << length;
        }

    // allocate memory + get the pointer to first obj
    char* newString = new char[length+1];

    //fill up obj with characters
    for(int i=0; i<length; i++){
        newString[i] = c[i]; 
    }
    //newString[length-1] = '\0'; 

    cout << newString;

    return newString;

}

//5. Write a function that finds the first occurrence of the C-style string x in s;
//          ie find x in s
char* findx(char* s, char* x){
    int length=0;
    char* pointer;

    //find length of x?
    for(int i = 0; x[i] != '\0'; i++){
        length++;
    }
    cout << "length of X is: " << length;


    for(int i =0; s[i]!='\0';i++){
       pointer = s + i; 
        int xLength=0;

        for(int j=0; x[j]!='\0';j++){
            if(s[i+j] == x[j])
                xLength++;
            else
                break;
        }

        if(length==xLength){
            return pointer;

    }

    
}

    return nullptr;
}



//stack overflow
//  Did not give runtime error
void stackoverflow(int i){
    stackoverflow(i);
}

//heap overflow - exercise06
void heapOverflow(){
    while(true){
        new long[1000000];
    }
}

// Exercise07
// Write a program that reads characters from cin into an array that you allocate on the free store
// Read individual charactersu ntil an exlamation mark (!)) is entered
//  DO NOT USE std::string    
//  DO NOT worry about memory exhaustion

void readIntoArray(){
    char* array = new char[100];
    int length = 0;

    cout << endl << endl; 
    cout << "\t\t\t\t\tExercise07\t\t\t\t\t";
    cout << endl << endl; 

   // cout << *array+0;
   // cout << *array+1;

   char c;
   for(int i=0; cin>>c;){
        if(c=='!')
            break;
        *array = c;
         array++;
         length++;
    }

    array = array-length;
    for(int i =0; i<4; i++)
        cout << *array++;
}


//Exercise 08
//Do exercercise 07 again, but this tiime read into a std::string rather than to memory you put on the free store
//      string knows how to use the free store for you
void readIntoString(){
    string s;
    
    for(char c; cin >> c; ) {
        if(c=='!')
            break;
        s.push_back(c);
    }
    cout << s;
}

//ex09
void stackGrowsWhichWay(){
 cout << "The stack grows which way?  - Address 1 and 2 of a short are the following: " ;
 short char1 = 1;   
 short char2 = 2;   

 short* address1 = &char1;
 short* address2 = &char2;

 cout << endl << endl << "Exercise 09" << endl << endl; 

 cout <<"address 1: " <<  (long long)address1 << endl
     << "address 2: " <<  (long long)address2;


 if(address1 < address2) 
     cout << endl << "This means  address1 is less than than address2 ie the stack grows up in memory addresses)" << endl ;
 else
     cout << endl << "This means  address1 is higher than than address2 ie the stack grows down in memory addresses)" << endl ;

 cout << endl << endl;
}

void heapGrowsWhichWay(){
 cout << "The heap grows which way?  - Address 1 and 2 of a short are the following: " ;

 short* address1 = new short {1};
 short* address2 = new short {1};

 cout << endl << endl << "Exercise 09" << endl << endl; 

 cout <<"address 1: " <<  (long long)address1 << endl
     << "address 2: " <<  (long long)address2;


 if(address1 < address2) 
     cout << endl << "This means  address1 is less than than address2 ie the heap grows up in memory addresses)" << endl ;
 else
     cout << endl << "This means  address1 is higher than than address2 ie the heap grows down in memory addresses)" << endl ;

 cout << endl << endl;
}

int main(){
   exercise01();
   exercise02();

   //Exercise03
   char c = 'C';
   char* cp=&c;
   to_lower(cp);

   cout << c;
   cout << endl << endl;

   //Exercise04
   const  char myString[]{ "STRING" }; // c-style stirng.. length is 7 // TODO: try this with ex 03 
   char* p = strdup(myString); // hmmm


   //stackoverflow(10);

   //cin >> c;


    // ex 05
   char s[]{ "helloWorld" };
   char x[]{ "Wo" };

   char* ptr = findx(s,x);

   cout << endl << endl << ptr << ptr[-1] ;

   //ex06
   //heapOverflow(); // terminate called after throwing an instance of 'std::bad_alloc'
                   // what():  std::bad_alloc



   cout << endl << endl;
   //ex07
    //readIntoArray();
   //Ex08
   //readIntoString();

   //ex09
   stackGrowsWhichWay();
   heapGrowsWhichWay();


//Exercise 10 : Looking at exercise 07 I  could potentially cause a overflow of the array ie out of bounds assignment by
//writing to the address [100] 

   // test of what happens
   readIntoArray(); // nothing happened :o
   // Essentially it is undefined behaviour
   //  The C++ guiding principle is "you don't pay for what you don't use". If your code is correct, you don't need bounds-checking, and you shouldn't be forced to pay for the overhead of runtime bounds-checking.
   //  because of it is a primitive C array it won't give any bounds checking ... 




}

