#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string name1 = "file_stream_open_modessass.txt";
    string name2 = "file_stream_open_modessasss.txt";
    string name = "file_stream_open_modessss.txt";

    ofstream of1{name1};        // defaults to ios_base::out
    ifstream if1{name1};        // defaults to ios_base::in

    ofstream ofs{name, ios_base::binary};  // ofstreams by default include 
                                        // io_base::out
    
    fstream fs{"myfile", ios_base::in|ios_base::out};       // Both in and out

    if(!fs);        // oops: we couldn't open that file that way


    ifstream ifs{"Readings"};
    if(!ifs);   // Error: can't open "readings" for reading

    ofstream ofs2{"no-such-file"};   //Create new file called -no-such-file
    ifstream ifs2{"no-ffile-of-this-name"};   //error:ifs will not be good()
    
    ofs << "hello this is append";
    ofs << "do you like it?";

}