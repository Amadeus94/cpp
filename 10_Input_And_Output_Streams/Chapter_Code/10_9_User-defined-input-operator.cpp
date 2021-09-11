#include <iostream>
using namespace std;
// Defining the input operator >> for a gfiven type and input format is basically an exercise inerror handling  - and is therefore often tricky 
    // Input is harder to deal with than output  -- more can go wrong with input than output 


class Date{
    public:
    int y,m,d;
    Date(int y, int m, int d){};
};




// The ideal is for an operator>>() NOT to consume(throw away) any characters that it didn't use
    // but thats too difficult in this case: we might have to read lots of characters before we caught a format error 
istream& operator>>(istream& is, Date& dd){
    int y,m,d;
    char ch1, ch2,ch3,ch4;
    is >> ch1 >> y >>ch2 >> m >> ch3 >> d >> ch4;
    if(!is) return is;
    if(ch1!='(' ||ch2!=','|| ch3!=','|| ch4!=')'){  // ooops: Format error
        is.clear(ios_base::failbit); // sets state to fail state
        return is;
    }
    dd=Date{y,m,d};     //update dd
    return is;
}