#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    cout << "name" << endl;
    string name;            
    cin >> name;        // input dennis ritchie
    cout << name << '\n';   //output dennis

    cout << endl
         << "name2" << endl;
    string name2;
    getline(cin, name2);    // dennis ritchie
    cout << name2 << '\n';  // dennis ritchie  -- >> can't do this so we use the getline() method 
                            // after you have the line you usually have to parse it 

    cout << endl
         << "ss1" << endl;
    string first_name;
    string second_name;
    stringstream ss{name};
    ss >> first_name;
    ss >> second_name;

    cout << endl
         << "ss2" << endl;
    string command;
    getline(cin, command);

    stringstream ss2{command};
    vector<string> words;
    for (string s; ss2 >> s;)
        words.push_back(s);
}