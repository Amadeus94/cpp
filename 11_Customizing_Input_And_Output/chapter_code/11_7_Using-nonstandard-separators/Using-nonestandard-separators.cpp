#include <iostream>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

class Punct_stream
{
public:
    Punct_stream(istream &is)
        : source{is}, sensitive{true} {}

    void whitespace(const string &s) { white = s; } // make s the whitespace set
    void add_white(char c) { white += c; };         // Add to the whitespace set
    bool is_whitespace(char c);                     // is c in the whitespace set?
    void case_sensitive(bool b) { sensitive = b; }
    bool is_case_sensitive() { return sensitive; }

    Punct_stream &operator>>(string &s);
    operator bool();

private:
    istream &source;      // character source
    istringstream buffer; // we let buffer do our formatting
    string white;         // characters considered "whitespace"
    bool sensitive;       // is the stream case-sensitive?
};

Punct_stream &Punct_stream::operator>>(string &s)
{
    while (!(buffer >> s))
    { // try to read from buffer
        if (buffer.bad() || !source.good())
            return *this;
        buffer.clear();

        string line;
        getline(source, line); // get a line from source

        // do character replacement as needed:
        for (char &ch : line)
            if (is_whitespace(ch))
                ch = ' '; // to space
            else if (!sensitive)
                ch = tolower(ch); // to lower

        buffer.str(line); // put stirng into stream
    }
    return *this; // teh result ie this puinctstream
}

// loops through the declared "whitespace" characters and checks the character against those --- notice no " " as this is automatically ignore by istreams
bool Punct_stream::is_whitespace(char c)
{
    for (char w : white)
        if (c == w)
            return true;
    return false;
}

// Allows us to check if Punct_stream is good automatically ie we can use it now in condition like:
// If(punct_stream) or if(punct_stream >> s) or while(ps>>s)
Punct_stream::operator bool()
{
    return !(source.fail() || source.bad()) && buffer.good();
}

main()
{
    //    string line;
    //    getline(cin, line); //read into line
    //    for (char &ch : line)
    //        switch (ch)
    //        {
    //        case ';':
    //        case '.':
    //        case ',':
    //        case '?':
    //        case '!':
    //            ch = ' ';
    //        }
    //
    //    stringstream ss(line); // make an istream ss reading from line
    //    vector<string> vs;
    //    for (string word; ss >> word;) // read words without punctuation chracters
    //        vs.push_back(word);
    //
    //    for (size_t i = 0; i < vs.size(); i++)
    //    {
    //        cout << endl
    //             << vs.at(i);
    //    }
    //
    //    //ps.whitespace(";:,.");
    //    //    for (string word; ps >> word;)
    //    //        vs.push_back(word);
    //
    //    //as.not
    //
    //    Punct_stream ps{cin};     // ps reads from cin
    //    ps.whitespace(";:.");     // semicolon, colon, and dot are also whitespace
    //    ps.case_sensitive(false); // not case-sensitive

    // last example in 11.7

    Punct_stream ps{cin};
    ps.whitespace(";:,.?!()\"{}<>/Q$@#%^*|~"); // these characters are considered whitespaces
    ps.case_sensitive(false);

    cout << "Please enter words\n";
    vector<string> vs;
    for (string word; ps >> word;)
    {
        vs.push_back(word);
    }

    sort(vs.begin(), vs.end()); // sort in lexigraphiccaal order
    for (int i = 0; i < vs.size(); ++i)
        // Very smart condition :  avoid duplicates
        if (i == 0 || vs[i] != vs[i - 1])
            cout << vs[i] << '\n';
}
