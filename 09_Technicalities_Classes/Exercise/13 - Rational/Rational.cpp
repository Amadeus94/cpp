#include <iostream>
// has two parts
// numerator
// denominator
// Example 5/6
// Provide these operators:
// +, -, *, /, ==.
// Also provide a conversion to double
// Why would I use a rational class? -
//  Because it can better handle the situations than making it manually
// ie efverything is contianed in the Datatype since this is a type

class Rational
{
public:
    Rational(int numerator, int denominator)
        : numerator{numerator}, denominator{denominator} {
                                    // assert values?
                                };
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
    void setNumerator(int newNumerator) { numerator = newNumerator; }
    void setDenominator(int newDenominator) { denominator = newDenominator; }
    double convertToDouble() { return static_cast<double>(numerator) / denominator; }

    void operator=(const Rational &r)
    {
        numerator = r.getNumerator();
        denominator = r.getDenominator();
    }

private:
    int numerator, denominator;
};

std::ostream &operator<<(std::ostream &os, const Rational &rational)
{
    return os << rational.getNumerator() << "/" << rational.getDenominator();
}

void alikeDenominator(Rational &rational1, Rational &rational2)
{
    int rational1Factor = rational1.getDenominator();
    int rational2Factor = rational2.getDenominator();
    int numeratorFactor1 = rational1.getNumerator();
    int numeratorFactor2 = rational2.getNumerator();

    while (rational1.getDenominator() != rational2.getDenominator())
    {
        if (rational1.getDenominator() > rational2.getDenominator())
        {
            rational2.setDenominator(rational2.getDenominator() + rational2Factor);
        }
        else if (rational2.getDenominator() > rational1.getDenominator())
        {
            rational1.setDenominator(rational1.getDenominator() + rational1Factor);
        }
    }

    int numerator1, numerator2, finalNumerator = 0;
    rational1.setNumerator((rational1.getDenominator() / rational1Factor) * rational1.getNumerator());
    rational2.setNumerator((rational2.getDenominator() / rational2Factor) * rational2.getNumerator());
}

Rational operator+(Rational rational1, Rational rational2)
{
    std::cout << std::endl
              << "Before: " << rational1 << " and " << rational2 << std::endl;
    alikeDenominator(rational1, rational2);
    std::cout << std::endl
              << "After: " << rational1 << " and " << rational2 << std::endl;
    int sumNumerator = rational1.getNumerator() + rational2.getNumerator();
    Rational sumRational(sumNumerator, rational1.getDenominator());
    std::cout << "Final: " << sumRational << std::endl;
    return sumRational;
}

Rational operator-(Rational rational1, Rational rational2)
{
    std::cout << std::endl
              << "Before: " << rational1 << " and " << rational2 << std::endl;
    alikeDenominator(rational1, rational2);
    std::cout << std::endl
              << "After: " << rational1 << " and " << rational2 << std::endl;
    //minuend = the suibtraction version of "sum"
    int minuendNumerator = rational1.getNumerator() - rational2.getNumerator();
    Rational sumRational(minuendNumerator, rational1.getDenominator());
    std::cout << "Final: " << sumRational << std::endl;
    return sumRational;
}

Rational operator*(Rational rational1, Rational rational2)
{
    int numerator = rational1.getNumerator() * rational2.getNumerator();
    int denominator = rational1.getDenominator() * rational2.getDenominator();
    return Rational(numerator, denominator);
}

// Flip the second fraction and multiply
Rational operator/(Rational rational1, Rational rational2)
{
    int numerator = rational1.getNumerator() * rational2.getDenominator();
    int denominator = rational1.getDenominator() * rational2.getNumerator();
    return Rational(numerator, denominator);
}

bool operator==(const Rational &rational1, const Rational &rational2)
{
    return rational1.getNumerator() == rational2.getNumerator() && rational1.getDenominator() == rational2.getDenominator();
};

bool operator!=(Rational &rational1, int &rational2)
{
    return true;
};

int main()
{
    Rational rational1 = Rational(37, 2);
    Rational rational2 = Rational(2, 18);
    //std::cout << rational1 + rational2;
    // std::cout << rational1 - rational2;
    //std::cout << rational1 * rational2;
    //std::cout << rational1 / rational2;
    //bool isTrue =  rational1 == rational2;
    //std::cout << isTrue;
    rational1 = rational2;
    std::cout << rational1;
}