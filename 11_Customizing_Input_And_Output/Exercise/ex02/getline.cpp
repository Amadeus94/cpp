#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Given a
//  file name and a word
//      Outputs each line each line that contains the word together with the line number

// I don't want comma or space
vector<string> splice(string line)
{
    int start = 0;
    bool isWhite = true;
    vector<string> words;

    for (size_t i = 0; i < line.size(); i++)
    {
        if (isalnum(line.at(i)) && isWhite)
        {
            start = i;
            isWhite = false;
        }
        if (!isalnum(line.at(i)) && !isWhite)
        {
            string word = line.substr(start, i - start);
            words.push_back(word);
            isWhite = true;
            start = i;
        }
    }
    return words;
}

int wordCount(vector<string> s, string word)
{
    int counter = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s.at(i) == word)
            counter++;
    }
    return counter;
}

void output(string filename, string word)
{
    ifstream ifs{filename};
    string line;

    cout << "The word " << word << "occurs for each line: " << endl << endl;

    cout<<"#\t\t wordcount" << endl;
    for (size_t i = 1; ifs.good();i++)
    {
        getline(ifs, line);
        vector<string> words = splice(line);
        int counts = wordCount(words,word);

        cout << i << ".\t\t" << counts << endl;
    }
}

int main()
{
//    string s = "omg hey how do you do boi";
//    //cout << s.substr(0,2);// is inclusive
//    vector<string> ss = splice(s);
//
//    for (size_t i = 0; i < ss.size(); i++)
//    {
//        cout << ss.at(i) << endl;
//    }

    output("test.txt", "omg");
}