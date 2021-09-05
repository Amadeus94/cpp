#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void error(string s1, string s2)
{
    cout << s1 << s2;
}

struct Point
{
    int x, y;
    // Missing to od an input operator >> from files I think
};

bool operator==(Point p1, Point p2){
    return p1.x==p2.y && p1.y == p2.y;
}

vector<Point> promptUserForPoint(int n)
{
    // Doesn't have a (1,2) format as irequirement for input
    vector<Point> points;
    for (size_t i = 0; i < n; i++)
    {
        Point point;
        cout << endl
             << "###############################" << endl
             << "Point " << i + 1 << endl
             << "x:";
        cin >> point.x;
        cout << endl
             << "y:";
        cin >> point.y;
        cout << endl
             << "###############################";
        points.push_back(point);
    }
    cout << endl;
    return points;
}

void printPoints(const vector<Point> v)
{
    for (Point p : v)
    {
        cout << "(" << p.x << "," << p.y << ")" << endl;
    }
}


void outputPointsToTXT(string txtFile, vector<Point> points){
    ofstream ost(txtFile);
    cout << "writing points to " << txtFile << "....";
    for (auto &&i : points)
    {
       ost  << i.x << "\t" << i.y << endl; 
    }
}

vector<Point> readPointsFromTXT(string txtFile){
    vector<Point> points;

    ifstream ist{txtFile};
    int x,y;
    while(ist >> x >> y){
        Point p;
        p.x = x*2;
        p.y = y*2;
        points.push_back(p);
    }
    return points;
}

void comparePoints(vector<Point> v1, vector<Point> v2){
    if(v1==v2)
        cout << endl << "They are the same";
    else
        cout << endl << "They are not equal ! - Something's wrong!";

}

int main()
{
   // auto original_points = promptUserForPoint(7);
   // printPoints(original_points);
   // outputPointsToTXT(string("points.txt"), original_points);
   vector<Point> processed_points1 = readPointsFromTXT(string("points.txt"));
   vector<Point> processed_points2 = processed_points1;
   comparePoints(processed_points1,processed_points2);


}

istream &operator>>(istream &is, Point point)
{
    cout << endl
         << "Provide input for Input for x & y: " << endl
         << ">";
    is >> point.x >> point.y;
    return is;
}

void program()
{
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if (!ist)
        error("Can't open input file: ", iname);

    vector<Point> points;
    for (Point p : points)
    {
        points.push_back(p);
    }
}