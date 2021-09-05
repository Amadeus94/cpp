#include <string>
#include <vector>

class Name_pairs
{
    std::vector<std::string> names;
    std::vector<double> ages;

public:
    void read_named(); // reads a series of names
    void read_ages();  // prompts the user for an age for each name
    void print();      // prints out the name[i], age[i] pair  ( One per line ) in the order determined by the name vector
    void sort();       // sorts the name vector in alphabetical order and reorganizes the age vector to match;
};


