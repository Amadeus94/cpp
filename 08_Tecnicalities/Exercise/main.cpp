#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
//Exercise 02
void print(string labeling, vector<int> numbers)
{
    cout << labeling << endl;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        cout << numbers.at(i);
        if (i != numbers.size() - 1)
            cout << ",";
    }
}

// Exercise 3
// Create a vector of fibonacci numbers nad print them using the function from exercise 2
// Creating the vector: fibonacci(x,y,v,n)
// x & y are ints  1,2,3,5,8 --- Start with this
// v is an empty vector <int>
// n is the number of elements to put into v

void fibonacci(int x, int y, vector<int> &v, int n)
{
    if (x > y || x == y || x < 0)
    {
        cout << "Not possible to have <fibnonacci";
        return;
    }
    v.push_back(x);
    v.push_back(y);
    int prev = y;
    int res = x + y;
    int temp;
    for (size_t i = 0; i < n - 2; i++)
    {
        temp = res;
        res += prev;
        prev = temp;
        v.push_back(res);
    }
}

// 1,2,3,4,5 => 5,4,3,2,1
// Should return new vector
vector<int> reverseVector(const vector<int> &v)
{
    vector<int> newVector;
    for (size_t i = v.size(); i > 0; i--)
    {
        newVector.push_back(v.at(i - 1));
    }
    return newVector;
};

// reverse same vector with swap
// ie without using another vector
// given it is equal
vector<int> reverseVectorSwap(vector<int> &v)
{
    int n = v.size() / 2;
    int temp;
    int last = v.size() - 1;
    for (size_t i = 0; i < n; i++, last--)
    {
        temp = v.at(i);
        v.at(i) = v.at(last);
        v.at(last) = temp;
        cout << endl;
    }

    return v;
}

vector<string> reverseVectorString(const vector<string> &v)
{
    vector<string> newVector;
    for (size_t i = v.size(); i > 0; i--)
    {
        newVector.push_back(v.at(i - 1));
    }
    return newVector;
}

// reverse same vector with swap
// ie without using another vector
// given it is equal
vector<string> reverseVectorSwapString(vector<string> &v)
{
    int n = v.size() / 2;
    string temp;
    int last = v.size() - 1;
    for (size_t i = 0; i < n; i++, last--)
    {
        temp = v.at(i);
        v.at(i) = v.at(last);
        v.at(last) = temp;
        cout << endl;
    }

    return v;
}

// Exercise 7
// read 5 names
// then 5 corresponding ages
// then print out the 5 name age pairs
// Sort the nmames via osrt(name.begin(), name.end()
// print out the the new pairs

// Hint: before soritng name, take a copy
//and use that to make a copy of age in the right order after sorting name

void readNames()
{

    vector<string> names;
    vector<int> ages;
    cout << "Hello, please enter 5 names separated with either a space or return" << endl
         << ">";

    string name;
    int age;

    for (size_t i = 0; i < 5; i++)
    {
        cin >> name;
        names.push_back(name);
    }

    cout << endl
         << "Now is time to assign age to each person:" << endl;

    for (size_t i = 0; i < names.size(); i++)
    {
        cout << "What is the age of " << names.at(i) << endl
             << ">";
        cin >> age;
        ages.push_back(age);
    }

    cout << endl
         << "thank you. The name and age pair are as follows:" << endl;
    cout << "#############################################" << endl;
    cout << "Name\t\tAge";
    for (size_t i = 0; i < 5; i++)
    {
        cout << endl
             << names.at(i) << "\t\t" << ages.at(i);
    }
    cout << endl
         << "#############################################" << endl;
    cout << "Now they are sorted by name and are print: " << endl;
    vector<string> sortedNames(names.begin(), names.end());
    vector<int> sortedAges;
    sort(sortedNames.begin(), sortedNames.end());
    for (size_t i = 0; i < sortedNames.size(); i++)
    {
        for (size_t j = 0; j < sortedNames.size(); j++)
        {
            if (sortedNames.at(i) == names.at(j))
            {
                sortedAges.push_back(ages.at(j));
            }
        }
    }

    cout << "#############################################" << endl;
    cout << "Name\t\tAge";

    for (size_t i = 0; i < 5; i++)
    {
        cout << endl
             << sortedNames.at(i) << "\t\t" << sortedAges.at(i);
    }
    cout << endl
         << "#############################################" << endl;
}

//Exercise 8
void readEndlessNames()
{

    vector<string> names;
    vector<int> ages;
    cout << "Hello, please enter names separated with either a space or return" << endl
         << ">";

    int age;

    for (string name; cin >> name;)
    {
        names.push_back(name);
    }
    cin.clear();

    cout << endl
         << "Now is time to assign age to each person:" << endl;

    for (size_t i = 0; i < names.size(); i++)
    {
        cout << "What is the age of " << names.at(i) << endl
             << ">";
        cin >> age;
        ages.push_back(age);
    }

    cout << endl
         << "thank you. The name and age pair are as follows:" << endl;
    cout << "#############################################" << endl;
    cout << "Name\t\tAge";
    for (size_t i = 0; i < names.size(); i++)
    {
        cout << endl
             << names.at(i) << "\t\t" << ages.at(i);
    }
    cout << endl
         << "#############################################" << endl;
    cout << "Now they are sorted by name and are print: " << endl;
    vector<string> sortedNames(names.begin(), names.end());
    vector<int> sortedAges;
    sort(sortedNames.begin(), sortedNames.end());
    for (size_t i = 0; i < sortedNames.size(); i++)
    {
        for (size_t j = 0; j < sortedNames.size(); j++)
        {
            if (sortedNames.at(i) == names.at(j))
            {
                sortedAges.push_back(ages.at(j));
            }
        }
    }

    cout << "#############################################" << endl;
    cout << "Name\t\tAge";

    for (size_t i = 0; i < names.size(); i++)
    {
        cout << endl
             << sortedNames.at(i) << "\t\t" << sortedAges.at(i);
    }
    cout << endl
         << "#############################################" << endl;
}

//Exercise 09
double sumPrices(const vector<double> &price,
                 const vector<double> &weight)
{
    double index = 0;
    for (size_t i = 0; i < price.size(); i++)
    {
        index += price.at(i) * weight.at(i);
    }
    return index;
}

//Exercise 10
// function double returns the largest element of a vector argument
double maxv(const vector<double> &v)
{
    double largest = -1;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v.at(i) > largest)
        {
            largest = v.at(i);
        }
    }
    return largest;
}

//Exercise 11
// find the largest, smallest, median and mean of a vector
// returnm eitehr via struct or pass them through reference arguments
struct VectorStats
{
    double largest, smallest, median, mean;
};

double minv(const vector<double> &v)
{
    double smallest = 100000000000000;
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v.at(i) < smallest)
        {
            smallest = v.at(i);
        }
    }
    return smallest;
}

bool compare(double a1, double a2)
{
    return a1 < a2;
}

double median(const vector<double> &vs)
{
    vector<double> v(vs.begin(), vs.end());
    sort(v.begin(), v.end());
    return v.size() % 2 == 0 ? v.at(v.size() / 2) : v.at(v.size() / 2 + 1);
}

double mean(const vector<double> &v)
{
    double mean = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        mean += v.at(i);
    }
    mean /= v.size();
    return mean;
}

VectorStats findVectorStats(vector<double> v)
{
    VectorStats vectorStats;
    vectorStats.largest = maxv(v);
    vectorStats.smallest = minv(v);
    vectorStats.mean = mean(v);
    vectorStats.median = median(v);
    return vectorStats;
}

//Exercise 12
// changes to const ref  - since we don't modify it
void print_until_s(const vector<string> &v, string quit)
{
    for (string s : v)
    {
        if (s == quit)
            return;
        cout << s << '\n';
    }
}

void print_until_ss(const vector<string> &v, string quit)
{
    int quitFound = 0;
    for (string s : v)
    {
        if (s == quit)
            quitFound++;
        if (quitFound == 2)
            return;
        cout << s << '\n';
    }
}

//Exercise 13
vector<int> numberOfCharacters(const vector<string> &v)
{
    vector<int> vi;
    int count = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        for (char s : v.at(i))
        {
            count++;
        }
        vi.push_back(count);
        count = 0;
    }
    return vi;
}

int largestStringIndex(const vector<string> &v)
{
    int largest = -1;
    int index = -1;
    int currentIndex;
    for (int i = 0; i < v.size(); i++)
    {
        currentIndex = v.at(i).size();
        if (currentIndex > largest)
        {
            largest = v.at(i).size();
            index = i;
        }
    }
    return index;
}

int smallestStringIndex(const vector<string> &v)
{
    int smallest = 100000;
    int index = -1;
    int currentIndex;
    for (int i = 0; i < v.size(); i++)
    {
        currentIndex = v.at(i).size();
        if (currentIndex < smallest)
        {
            smallest = v.at(i).size();
            index = i;
        }
    }
    return index;
}

string lexographicallyLargestString(const vector<string> &v)
{
    string lexoLargest = v.at(0);
    for (int i = 1; i < v.size(); i++)
    {
        if (lexoLargest < v.at(i))
        {
            lexoLargest = v.at(i);
        }
    }
    return lexoLargest;
}

string lexographicallySmallestString(const vector<string> &v)
{
    string lexoSmallest = v.at(0);
    for (int i = 1; i < v.size(); i++)
    {
        if (lexoSmallest > v.at(i))
        {
            lexoSmallest = v.at(i);
        }
    }
    return lexoSmallest;
}


//Exercise 14
void f(const int s){
    cout << "hello world";
}

int main()
{
    //Exercise 2
    //  vector<int> test1 = {1,2,3,4,5,6,7};
    //  print("Cod Weight", test1);

    // Exercise 3
    //    vector<int> v = {};
    //    fibonacci(1,2,v, 10);
    //    for (size_t i = 0; i < v.size(); i++)
    //    {
    //       cout <<  v.at(i) << endl;
    //    }
    //   //Exercise 4
    //    vector<int> v = {};
    //    fibonacci(1,2,v, 44);
    //    for (size_t i = 0; i < v.size(); i++)
    //    {
    //       cout <<  v.at(i) << endl;
    //    }
    //    // Result: n=44 when the integer peaked and goes negative
    //

    //Exercise 5
    //    vector<int> j = {1,2,3,4,5};
    //    vector<int> reverseJ=reverseVector(j);
    //    for (size_t i = 0; i < reverseJ.size(); i++)
    //    {
    //        cout << reverseJ.at(i);
    //    }

    //Exercise swap
    //    vector<int> j = {1, 2, 3, 4};
    //    vector<int> reverseJ = reverseVectorSwap(j);
    //    for (size_t i = 0; i < reverseJ.size(); i++)
    //    {
    //        cout << reverseJ.at(i);
    //    }

    //Exercise 6
    //        vector<string> j = {"hello there","How are you?", "yes", "omfg"};
    //        vector<string> reverseJ=reverseVectorString(j);
    //        for (size_t i = 0; i < reverseJ.size(); i++)
    //        {
    //            cout << reverseJ.at(i);
    //        }

    //Exercise swap
    //   vector<string> j = {"1","2", "3", "4"};
    //   vector<string> reverseJ = reverseVectorSwapString(j);
    //   for (size_t i = 0; i < reverseJ.size(); i++)
    //   {
    //       cout << reverseJ.at(i);
    //   }

    //Exercise 7
    //readNames();

    //Exercise 08
    //readEndlessNames();

    //Exercise 09
    //    vector<double> price = {1,1,1,2,2,3,4};
    //    vector<double> weight = {10,10,10,10,10,10,20};
    //   cout <<  sumPrices(price,weight);

    //Exercise 10
    //    vector<double> v = {1,232,2342,63453,45234,4,421,432,23,2, 7777777};
    //    cout << maxv(v);

    //  Exercise 11;
    //   vector<double> v = {1, 2, 34, 5, 34, 5234, 34234, 2342, 34, 23, 42, 3};
    //   VectorStats vs = findVectorStats(v);
    //   cout << vs.largest << endl
    //        << vs.smallest << endl
    //        << vs.median << endl
    //        << vs.mean << endl;

    //Exercise 12
    //   vector<string> s =  {"hello", "hi", "123", "omg", "jesus", "q", "ohnm","sigh", "omg", "q", "lol", "k"};
    //   string q = "q";
    //  // print_until_s(s, q);
    //   print_until_ss(s, q);

    //Exercise 13

    vector<string> s = {"hello", "hi", "123", "omg", "jesus", "q", "ohnm", "sigh", "omg", "q", "lol", "k", "kasldkfaslkdfs"};
    vector<int> vi = numberOfCharacters(s);
    cout << "\tString\tCount" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << "\t" << s.at(i) <<"\t"<< vi.at(i) << endl;
    }
    cout << s.at(largestStringIndex(s)) << " is the longest string with " << s.at(largestStringIndex(s)).size() << " characters"
         << " found at index " << largestStringIndex(s) << endl;
    cout << s.at(smallestStringIndex(s)) << " is the smallest string with " << s.at(smallestStringIndex(s)).size() << " characters"
         << " found at index " << smallestStringIndex(s) << endl;
    cout << "The lexographically largest string is " << lexographicallyLargestString(s) << endl;
    cout << "The lexographically smalelst string is " << lexographicallySmallestString(s) << endl;


}