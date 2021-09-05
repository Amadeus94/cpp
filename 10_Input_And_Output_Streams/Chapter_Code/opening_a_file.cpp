#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct Point
{
    int x, y;
};

std::istream &operator>>(std::ifstream &is, Point &obj)
{
    is >> obj.x >> obj.y;
    return is;
}

int main()
{
    // Open File 
    cout << "please enter input file name: ";
    string iname;
    //  cin >> iname; - If you want them read the file in but cba -- also you need provide FULL name aka separated.txt ... not only separated
    iname = string("numberSeparatedFile.txt");

    ifstream ist{iname};                    // ist is an input stream for the file named name
    if (!ist)                               // Checks if the file was properly opened
        throw "Division by zero condition"; // Did not know I could throw a stirng


    //Read numbers from file
    vector<Point> points;
    for (Point p; ist >> p;)
    {
        points.push_back(p);
    }

    // Output to console
    cout << endl;
    for (int i = 0; i < points.size(); i++)
    {
        cout << i << ".\t" << "(" << points.at(i).x << "," << points.at(i).y << ")" << endl;
    }

    //Output to file
    cout << "Please enter name of output file: ";
    string oname;
    cin >> oname;
    ofstream ost{oname};
    if(!ost) 
        throw "Can't open output file ";
    
    

}
