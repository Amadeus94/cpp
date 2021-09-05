#include <iostream>

namespace X
{


    int var;
    void print()
    {

        std::cout << "hello from X" << std::endl << "Value is: " << var << std::endl << std::endl;
    }

} // namespace name
namespace Y
{


    int var;
    void print()
    {
        std::cout << "hello from Y" << std::endl << "Value is: " << var << std::endl << std::endl;
    }

} // namespace name

namespace Z
{


    int var;
    void print()
    {

        std::cout << "hello from Z" << std::endl << "Value is: " << var << std::endl << std::endl;
    }

} // namespace name



int main()
{
    X::var = 7;
    X::print();
    using namespace Y;
    var = 9;
    print();
    {
        using Z::print;
        using Z::var;
        var = 11;
        print();
    }
    print();
    X::print();
}
