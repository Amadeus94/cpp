#include <string>

class Patron
{
public:
    std::string getUsername() { return username; }
    std::string getLibraryCarNumber() { return libraryCardNumber; }
    int getLibraryFees() { return libraryFees; }
    void setFee(int newFee) { this->libraryFees = newFee; }
    bool isUnpaid()
    {
        if (this->libraryFees > 0)
            return true;
        else
            return false;
    }

private:
    std::string username;
    std::string libraryCardNumber;
    int libraryFees;
};