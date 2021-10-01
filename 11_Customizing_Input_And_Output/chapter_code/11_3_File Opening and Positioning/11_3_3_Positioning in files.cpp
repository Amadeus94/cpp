#include <iostream>
#include <fstream>
using namespace std;


int main(){
    fstream fs{"karl"};
    if(!fs) cout << "error boi";

    fs.seekg(139); // Move reading position (g for "get") to 5 ( the 6th character)
    char ch;
    fs >> ch;   //read and increment reading position
    cout << "Character[5] is " << ch << '(' << int(ch) << ")\n";

    fs.seekp(139);    //move writing position (p for "put") to 1 
    fs << 'y';      // write and increment writing position

}