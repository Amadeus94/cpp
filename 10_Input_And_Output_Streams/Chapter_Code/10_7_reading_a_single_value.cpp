#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    //Ugly but sort of works

    cout << "please enter an integer in the rnage 1 to 10 (includsive):\n";
    int n = 0;
    while (cin >> n)
    { //read
        if (1 <= n && n <= 10)
            break; // check range
        cout << "Sorry"
             << n << " is not in the [1:10] range please try again \n";
    }
    //....use n here...

    //Alternative: don't like using breaks you can combuine the reading and range settings
    cout << "please enter an integer in the rnage 1 to 10 (includsive):\n";
    int n = 0;
    while (cin >> n && !(1 <= n && n <= 10))
        cout << "Sorry"
             << n << " is not in the [1:10] range please try again \n";

    //Why only "sorts of works?"
    /*
    Problems:

    1. The user typing an out-of-range value
        Fix: Handle the problem in the code doing the read
    2. getting no value( end of file)
        fix: Throw an exception to let someone else handle the problem (potentially terminating the program)
    3. The user typuing soemething of the wrong type ( here, not an integer)
        fix: Ignore the problem 


    It is a choice on how you deal with it .. if only you use program then for all means skip all the verifications 
    ctrl+z 




    */
}

//10.7.1
// handleOutOfRange_and_InputOfTheWrongType method
// Code is messy and long winded
// Does too much
// reading values, prompting the user for input, writing eroror messages, skipping past "bad" input characters, testing the input against a range
// How to fix?? Separate lolgically distinct concerns into separate functions
void ReadSingleValue()
{
    cout << "please enter an integer in the rnage 1 to 10 (includsive):\n";
    int n = 0;
    while (true)
    {
        if (cin)
        { // we got an integer; now check it
            if (1 <= n && n <= 10)
                break; // check range
            cout << "sorry"
                 << n << " is not in the [1:10] range please try again \n";
        }
        else if (cin.fail())
        {                // we found something that wasn't an integer
            cin.clear(); // set the state back to good();
                         // we want to look at the characters
            cout << "sorry, that was not a number; please try again\n";
            for (char ch; cin >> ch && !isdigit(ch);) // throw away non digits
            {                                         // may be reading from a file  or the input written .. if there is no digit then fuck it  and throws nondigits out
                /*nothing*/;
            }
            if (!cin)
                cout << "error"; // we didn't find a digit: give up
            cin.unget();         //put the digit back, so that we can read the number
                                 // not entirely sure how this works
        }

        cout << "please enter an integer in the rnage 1 to 10 (includsive):\n";
        int n = 0;
        while (cin >> n && !(1 <= n && n <= 10))
            cout << "sorry"
                 << n << " is not in the [1:10] range please try again \n";
    }
}

void skip_to_int() // utility function
{
    if (cin.fail())
    {
        cin.clear();
        for (char ch; cin >> ch;)
        {
            if (isdigit(ch) || ch == '-')
            {
                cin.unget(); // put the digit back
                             // so that we can read the number
                return;
            }
        }
    }
    cout << "error - No input"; // eof, or bad: give up
}

// Improved version because of extract method
// still too long and messy     But way better still
void ReadSingleValueV2()
{
    cout << "please enter an integer in the rnage 1 to 10 (includsive):\n";
    int n = 0;
    while (true)
    {
        if (cin >> n) // changed
        {
            if (1 <= n && n <= 10)
                break;
            cout << "sorry"
                 << n << " is not in the [1:10] range please try again \n";
        }
        else
        { // Changed
            cout << "Sorry, that was not a numbner; Please try again\n";
            skip_to_int();
        }
    }
}

// code still messy and too long to use many times in a program
    // What operation would we relaly like to have  ?
        // 1. A functio nthat reads an int, any int
        // 2. A function that reads an int of a given range 

int get_int();  // read an int from cin
int get_int(int low, int high); // read an in in [low:high] from cin 

int get_int(){          // keeps reading until it finds a int
                            // to get out use ctrl+z or end of file
                                // throws eception
    int n=0;
    while(true){
        if(cin >> n) return n;
    }
    cout << "sorry, that was nto a numebr; please try agian \n";
    skip_to_int();
}

int get_int(int low, int high){
    cout << "Please enter an integer in the range "  << low << " to " << high << " (inclusive):\n";

    while(true){
        int n = get_int();
        if(low<=n && n<=high) return n;
        cout << "sorry not between high and low ranges";
    }
}


// Remember to catch exceptions somweehere, though, if you want decent error messages for the (probably rare ) case when get_int() really couldn't read anumber for us 



// Unfortunately the code is still a bit messy 
//      It is rtedious to repeat the terminator test if we read a lot of files
//          We could write a function to deal with that 

// Somewhere: make ist throw if it goes bad: 
//ist.exceptions(ist.exceptions()|ios_base::badbit);

void end_of_loop(istream& ist, char term, const string& message){
    if(ist.fail()){
        ist.clear();
        char ch;
        if(ist>>ch && ch==term) return;     // all is fine 
        cout << message << "hi"; // throw error
    }
}

// thgis makes the input loop look like this:

void currentInputloop(ifstream ist){
    for (char s; ist >> s ; ) // read until eof
    {
        // Maybe check that char is valid 
        
        // do something with var


    }
    end_of_loop(ist, '|',"Bad termination of file"); // test if we can continue
   // ^^ Only triggered if stream is in fail state) 
}


// Whenever we want to sdo anything of interest with readings s we have tos tort them 