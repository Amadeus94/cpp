#include <fstream>
#include <vector>
using namespace std;

void dont_do_this(string s){
    int m;
    if(s=="jan")
        m=1;
    else if(s=="feb")
        m=2;
    // and so on
}// tedious and horirble 
 


void do_this(ifstream ist){
    vector<string> month_input_tbl = {
        "jan", "feb", "mar" // and so on
    };
    // or even better use a map 
}



