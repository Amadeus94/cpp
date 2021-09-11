#include <iostream>
#include <fstream>
using namespace std;

// Assumption was We could have read a file from its beginning until end of file
//      reasonable assumption because we often applyh separate checks to ensure that file is valid
//          However we often want to chweck our reads as we go along
//  Choices: Read into iuntil we can't anymore and hcekc errors why we cant read anymore "fail() bad() eof() etc."
//          or use a designate a terminator
void terminatorTest(ifstream ist){
    if(ist.fail()){
        ist.clear();
        char ch;
        if(!(ist>>ch&&ch=='|')) cout << "error"; // uses | as terminator
    }
}

// Terminators are very useful when you read files with nested constructs
//  such as a file of montly readings containing diaily readings, containing hoursly readings, etc.   
// So always consider if a terminator would be best 