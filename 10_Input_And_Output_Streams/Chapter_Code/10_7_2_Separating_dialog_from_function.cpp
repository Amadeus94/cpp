#include <iostream>
using namespace std;

// The fyunctions mix up reading with writing messages to the users
// this is okay for simple program but in a large program we might want to vary the messages written to the user

// For instance

int get_int(int, int, char[], char[]); // dummy
// Actually the better way is:
int get_int(int, int, const string&, const string&); // dummy


int strength = get_int(1, 10, "enter strength", "not in range, try again ");
int main()
{
    std::cout << "strength: " << strength << '\n';
}


// NOTE:
    // UItility functions that we use in many parts of a program shouldn't hjave messages "hardwired" into them" 
    // Library function s that are meant for use in many programs shouldn't write to the user at all
        // after all - the library writer may not even know that the program in which the library runs is used on am achine with a human watching 
            // which is also why error() does not only write an error message 

    // Used mainly to support multiple langauges