#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream ifs{"Hey.txt"};
    if (!ifs.good())
        cout << "not good input";

    string line;
    getline(ifs, line);
    stringstream ss{line};

    for (int i = line.size() - 1; i >= 0; i--)
    {
        ss << line.at(i);
    }

    string reversedLine = ss.str();

    cout << reversedLine;
}