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
    ifstream ifs{"test.txt"};
    if (!ifs.good())
        cout << "das nichten guten";

    vector<string> words;
    for(string word; ifs >> word;)
        words.push_back(word);
   for (int i = words.size() - 1; i >= 0; i--)
   {
       cout << words.at(i) << " ";
   }
}