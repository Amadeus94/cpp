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

    ifstream ifs{"number.txt"};
    if (!ifs)
        cout << "error";

    vector<int> values;

    for (int val; ifs >> val;)
    {
        values.push_back(val);
    }
    sort(values.begin(), values.end());

    int counter = 0;
    for (int i = 0; i < values.size(); i++)
    {
        counter++;
        if (i != 0)
        {
            if (i != 0 && values.at(i) == values.at(i - 1))
            {
                continue;
            }
        }

        cout << values.at(i) << '\t';
        if (counter > 1)
            cout << counter;
        cout << endl;
        counter = 0;
    }
}