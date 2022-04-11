#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void disemVowel(string fileName)
{
    ifstream ifs{fileName};
    string vowels = "eyuioåa";

    ofstream ofs{fileName + "2"};

    bool notGood = false;
    for (char c; ifs >> c;)
    {
        notGood = false;

        for (char cc : vowels)
        {
            if (cc == c)
            {
                cout << "hi";
            }
            break;
            ofs << c;
        }
    }
}

class Punct_stream
{
public:
    Punct_stream(ifstream &ifs) : source{ifs}, sensitive{true} {}
    void vowelList(const string v) {
        //C++ doesn't allow non-constant values for the size of an array. That's just the way it was designed.
            const int size = v.size();


         
         }
    void add_vowels_to_vowelList(char v) { vowels + v; }
    bool case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() { return sensitive; }

    bool is_vowel(char c);

    Punct_stream &operator>>(string &s);
    operator bool();

private:
    ifstream &source;
    istringstream buffer;
    string vowels;
    bool sensitive;
};

string removeCharacters(string s, char c)
{
    s.erase(remove(s.begin(), s.end(), c), s.end());
    return s;
}

// Another way of doing it is to simnply iterate through characters then push back to vector



Punct_stream &Punct_stream::operator>>(string &s)
{
    // https://stackoverflow.com/questions/64765238/how-do-i-specify-more-than-one-delimiter-for-cin-ignore-in-c

    char delim[] = {'a', 'e'};
    int delim_len = sizeof(delim) / sizeof(char);
    //while (std::find(delim, delim + delim_len, buffer.peek()) == delim + delim_len) && !std::cin.eof() )
    std::cin.ignore(1);

    while (!(buffer >> s))
    { // try read from buffer
        if (buffer.bad() || !source.good())
            return *this;
        buffer.clear();

        string word;

        //getline(source, line);
        // ss.ignore() - Extract and discard characters
        //buffer.ignore('')
        // Do character replacement as needed
        //     for (char &ch : line)
        //         if (is_vowel(ch))
        //             ch = 'ð';
        //     buffer.str(line);
    }
    return *this;
}
//Punct_stream &Punct_stream::operator>>(string &s)
//{
//    for (size_t i = 0; i < vowels.size(); i++)
//    {
//        buffer.ignore(vowels.at(i));
//    }
//
//    int counter =1;
//
//    while (!(buffer >> s))
//    { // try read from buffer
//        if (buffer.bad() || !source.good())
//            return *this;
//        buffer.clear();
//
//        string line;
//        getline(source, line);
//
//        cout << counter << ".\t" << line << endl;
//// ss.ignore() - Extract and discard characters
//    //buffer.ignore('')
//        // Do character replacement as needed
//   //     for (char &ch : line)
//   //         if (is_vowel(ch))
//   //             ch = 'ð';
//   //     buffer.str(line);
//    }
//    return *this;
//}
//
bool Punct_stream::is_vowel(char c)
{
    for (char v : vowels)
        if (c == v)
            return true;
    return false;
}

main()
{
    string testString = "hi hello there how you dozies";
    ifstream ifs{"vowels.txt"};
    Punct_stream ps{ifs};
    string line;
    ps.vowelList("aeuioåæø");
    ps >> line;

    cout << line << endl;

    cout << testString << "\t" << testString.size() << endl
         << removeCharacters(testString, 'e') << "\t" << testString.size() << endl;
    disemVowel("vowels.txt");
}