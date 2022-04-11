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
    ofstream fout;
    fout.open("file.bin", ios::binary | ios::out);

    int a[4] = {100023, 23, 42, 13};
    fout.write((char *)&a, sizeof(a));

    fout.close();
}