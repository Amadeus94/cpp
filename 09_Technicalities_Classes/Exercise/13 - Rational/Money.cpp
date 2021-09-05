#include <iostream>
#include <string>

enum class Currency
{
    dkk,
    usd
};

class Money
{
public:
    void setMoney(double money)
    {
        int dollars;
        int cents = money;
        int totalCents = 0;
        for (size_t i = 0; i < int(money) / 100; i++)
        {
            cents -= 100;
            dollars += 1;
        }
        totalCents = (dollars * 100) + cents;
        //     std::cout << "Dollars: " << dollars << std::endl;
        //     std::cout << "Cents: " << cents << std::endl;
        //     std::cout << "Total Cents" << totalCents;
        this->cents = totalCents;
    }
    long int getCents() const { return cents; };
    long int getDollars()
    {
        int roundingDollars = cents % 100 < 50 ? roundingDollars = 0 : roundingDollars = 1;
        int dollar = cents / 100 + roundingDollars;
        return dollar;
    }
    Money() {}
    Money(long int cents) : cents{cents} {}
    Money(long int cents, Currency currency) : cents{cents}, currency{currency}
    {
    }

    long int convertUSDtoDK(long int cents)
    {
        return cents * 6, 34;
    }

    long int convertDKKTOUSD(long int cents)
    {
        return cents * 0.16;
    }

    friend std::istream &operator>>(std::istream &is, Money &money)
    {
        std::string currency;
        std::cout << "Input your amount of money in cents/dkk" << std::endl
                  << ">";
        is >> money.cents;
        std::cout << "Input your currency dkk or usd << ";
        is >> currency;
        currency == "usd" ? money.currency = Currency::usd : money.currency = Currency::dkk;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Money &money)
    {
        long int currentCents = money.getCents();
        int dollars = 0;
        for (size_t i = 0; i < money.getCents() / 100; i++)
        {
            currentCents -= 100;
            dollars += 1;
        }
        if (money.currency == Currency::usd)
            os << "Total amount in dollars: $" << dollars << "." << currentCents;
        else
            os << "Total amount in danske kroner: DKK" << dollars << "." << currentCents;

        return os;
    }

private:
    long int cents; // .5 of a cent rounds up
    Currency currency;
};

int main()
{

    // Money money;
    // money.setMoney(49);
    // // std::cout << std::endl << std::endl << money;
    // int dollars = money.getDollars();
    // std::cout << dollars;

    Money money(200, Currency::dkk);
    std::cout << money << std::endl;
    std::cin >> money;
    std::cout << std::endl << money; 
}