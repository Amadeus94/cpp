#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
// Write a program that produces the sum of all numbers in a file of whitespace-separated integers.

int main()
{

    string name = string("numbers_whitespaceseparated.txt");
    fstream ist{name};

    vector<int> v;

    for (int i; ist >> i;)
    {
        v.push_back(i);
    }

    int result = 0;
    for (int num : v)
    {
        result += num;
    }

    cout << "The sum of the file " << name << " is " << result;

    return 0;
}
