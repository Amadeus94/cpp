#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string removeVowels(vector<char> vowels, string word)
{
    string s = "";
    stringstream ss{s};

    bool isVowel = false;
    for (size_t i = 0; i < word.size(); i++)
    {
        isVowel = false;

        for (size_t j = 0; j < vowels.size(); j++)
        {
            if (word.at(i) == vowels.at(j))
            {
                isVowel = true;
                break;
            }
        }
        if (!isVowel)
            ss << word.at(i);
    }
    ss >> s;

    return s;
}

int main()
{
    // Vowels
    vector<char> vowels = {'a', 'e', 'y', 'u', 'i', 'o'};

    //cout << removeVowels(vowels, "hello");

    // read from file -- File does not contain annoying signs like !#"¤¤¤¤"
    ifstream ifs{"vowels.txt"};

    vector<string> wordsWithVowels;
    for (string word; ifs >> word;)
    {
        wordsWithVowels.push_back(word);
    }

    for (size_t i = 0; i < wordsWithVowels.size(); i++)
    {
        cout << wordsWithVowels.at(i) << " ";
        if (i % 13==0 && (i!=0)) 
            cout << endl;
        /* code */
    }
    
    cout << endl << endl << "becomes " << endl << endl;
    vector<string> wordsWithoutVowels;
    for (int i = 0; i< wordsWithVowels.size() ; i++)
    {


        string word = wordsWithVowels.at(i);
        string withoutVowel = removeVowels(vowels, word);
        wordsWithoutVowels.push_back(withoutVowel);
    }

    for (size_t i = 0; i < wordsWithoutVowels.size(); i++)
    {
        cout << wordsWithoutVowels.at(i) << " ";
        if (i % 13==0 && (i!=0))
            cout << endl;
    }

    // write to file
    ofstream ofs{"output.txt"};
    for (size_t i = 0; i < wordsWithoutVowels.size(); i++)
    {
        ofs << wordsWithoutVowels.at(i) << " ";
        if (i % 13==0 && (i!=0)) 
            ofs << endl;
    }


}