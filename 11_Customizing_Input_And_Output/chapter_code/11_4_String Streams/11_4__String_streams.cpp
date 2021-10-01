#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


// stringstreams are generally used when we want to separate actual I/O from processing 
// stringstreams can be used to filter undesireable characters from our input 

// tl;dr stringstreams can bee seen as a mechanism for tailoring I/O to special needs and tastes
    // be it reading it in a special way (Istringstream)
    // or formatting it in a special way(ostringstream ) 
    // or other htings 

// istringstream usuallyu intitialized witha  string and then read the caracters from that string using input operations
// ostringstream usually intiializedd with a empty string and then fill it using output operations 


// important thing to learn is ss.str(s) 
    // returns a copy of stringstreams string  

double str_to_double(string s)
    //If possible, convert characters in s to floating-point value
{
    istringstream is{s};        //make a stream so that we can read from s
    double d;
    is >> d;
    if(!is) cout << "error, double format error " << s; 
    return d;
}

//void my_code(string label, Tempterature temp){
//    //...
//    ostringstream os;   //stream for composing a message
//    os << setw(8) << label << ": " 
//    << fixed << setprecision(5) << temp.temp << temp.unit;
//    someobject.display(Point(100,100), os.str().c_strr());
//}

int get_next_number(){
    return 3;
}

int main(){
    // you can use a string as the source of an istream or the target for an ostream 

    // istream that reads from a string is called an istringstream
    // an ostream that reads writes to a string is called a ostringstring 

    // stringstream are especially useful for extracting numeric values from a string 
    double d1 = str_to_double("12.4");              // testing
    double d1 = str_to_double("1.34e-3");
    double d1 = str_to_double("twelve point three"); // will call error()


    // construct strings by concatenation
    int seq_no = get_next_number();          // get the number of a log file
    ostringstream name;
    name << "myfile" << seq_no << ".log";   // e.g. myfile.log
    ofstream logfile{name.str()};           //e.g open myfile17.log
}