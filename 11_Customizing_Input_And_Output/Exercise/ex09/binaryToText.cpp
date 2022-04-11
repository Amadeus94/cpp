#include <iostream>
#include <algorithm>
#include <sstream>  
#include <iomanip>  
#include <vector>   
#include <string>   
#include <fstream>   


using namespace std;


template <class T>
char *as_bytes(T &i) // needed for binary I/O
{
    void *addr = &i; // get the address of the first byte
    // of memory used to store the object
    return static_cast<char *>(addr); // treat that memory as bytes
}

int main()
{
    //open an istream for binary inpuit from a file
    cout << "please enter input file name\n";
    string iname;
    cin >> iname;
    ifstream ifs{iname, ios_base::binary}; // note: stream mode
    if (!ifs)
        cout << "Can't open input file  " << iname; // binary tells the stream not to try anything clever with the bytes

    //open an ostream for binary output to a file:
    cout << "plase enter output file name\n";
    string oname;
    cin >> oname;
    ofstream ofs{oname};
    if (!ofs)
        cout << "error - can't open output file ", oname; // binary tells the stream not to try anything clever with the bytes

    vector<int> v;

    //read from binary file:
    for (int x; ifs.read(as_bytes(x), sizeof(int));) // note: reading bytes
        v.push_back(x);
    
    //Do..do something wwith v ..

    //write to binary file

    for(int x: v)
            ofs << x;
}