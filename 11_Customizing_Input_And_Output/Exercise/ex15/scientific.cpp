#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/*
Write a program that reads a file of whitespace-separated number 
    and output them in order (lowest value first)
        One using scientific format
        precision 8
        in 4 fields of 20 characters per line
*/

int main()
{
    ifstream ifs{"number.txt"};
    vector<int> v;
    for (int i; ifs >> i;)
    {
        v.push_back(i);
    }
    sort(v.begin(), v.end());

    ofstream ofs{"number2.txt"};
    ofs << scientific << setprecision(8);

    string all;
    stringstream ss{all};

    for (size_t i = 0; i < v.size(); i++)
    {
        ss << v.at(i) << " ";
    }

    cout << ss.str() << endl;

    vector<string> numberwords;
    for (int i = 0; i < v.size(); i++)
    {
        numberwords.push_back(to_string(v.at(i)));
    }

    cout << "siiiiize";

    int fields = 0;
    int size = 0;

    for (int i = 0; i < numberwords.size(); i++)
    {
        if (i == 0)
        {
            ofs << setprecision(8) << scientific << numberwords.at(i) << "\t";
            size+=numberwords.at(i).size();
            fields++;
            continue;
        }

        size += numberwords.at(i).size()+1;//added one for \t

        if (size > 20  || fields % 4 == 0 && i != 0)
        {
            fields = 0;
            if(size>20){
                size-=20;
            }
            ofs << '\n';
        }

        ofs << setprecision(8) << scientific << numberwords.at(i) << "\t";
        fields++;
    }
}