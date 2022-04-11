#include <iostream>
#include <algorithm>
#include <sstream>  
#include <iomanip>  
#include <vector>   
#include <string>   
#include <fstream>   


using namespace std;

// Write a function split()
    // that returns a vector of whitespace-space separated substrings from the argument s
vector<string> split(const string& s){
    stringstream ss{s};
    string s2;
    vector<string> v;

    while(ss>>s2)
        v.push_back(s2);
        //v.push_back(" ");
    
    return v;
}

int main()
{
    vector<string> v = split("Hello there how are you doing");
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v.at(i);
    }
}