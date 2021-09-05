#include <string>
#include <vector>

class Name_pairs
{
public:
    void read_named(); // reads a series of names
    void read_ages();  // prompts the user for an age for each name
    void sort();       // sorts the name vector in alphabetical order and reorganizes the age vector to match;
    std::vector<std::string> names() const {return namesVector;};
    std::vector<double> ages() const {return agesVector;};

private:
    std::vector<std::string> namesVector;
    std::vector<double> agesVector;
};
