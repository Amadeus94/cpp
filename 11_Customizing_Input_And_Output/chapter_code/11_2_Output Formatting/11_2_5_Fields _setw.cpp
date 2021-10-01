#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void namecout(string firstName, string lastName, string phone, string email ){
    cout << '|' << setw(10) << firstName ;
    cout << '|' << setw(12) << lastName;
    cout << '|' << setw(8) << phone;
    cout << '|' << setw(20) << email << "|\n";
}


int main()
{
   // // In scientifix and fixed formats a programmer can contorl exactly hwo much space a value tkes up on output
   // // The equivalent in integers / strings is the setw() manipulator which are called "Fields"
   // // setw = set field with manipulator
   //     // usecases:    printing out tables aaaaaaaaaaaaaaaaaaaaa
   // cout << 123456
   //      << '|' << setw(4) << 123456 << '|' // 123456 doesnt fit into setw(4) ie is over 4 characters long .. ignores it
   //                                         // Does this because it rather breaks format than bad data output
   //                                         // Bad formattings is almost always preferable to bad output data 

   //      << setw(8) << 123456 << '|'        // prints |  123456|
   //      << 123456 << "|\n\n\n\n"; // setw doesn't STICK - ie you need to reapply before evewrytime you need it



   // // Fields can also be used for floating-påoint numbers and strings

   // cout  << 12345 << '|' << setw(4) << 12345 << '|'
   //       << setw(8) << 12345 << '|' << 12345 << "|\n";
   // cout << 1234.5 << "|" << setw(4) << 1234.5 << '|'
   //      << setw(8) << 1234.5 << '|' << 1234.5 << "\n";
   // cout << "asdfg" << '|' << setw(4) << "asdfg" << "|"
   //     << setw(8) << "asdfg" << "|" <<  "asdfg" << "|\n";

   // // Try this
   // //  Make a simple table including the 
   // //      lastName,FirstName,Phonenumber, emailAddress and atleast of five of your friends

    namecout("Last Name", "First Name", "Phone", "Email");
    namecout("karl", "hansen", "25393203", "kls@gmas.so");
    namecout("karl", "hansen", "25393203", "kls@gmas.so");
    namecout("karl", "hansen", "25393203", "kls@gmas.so");
    namecout("karl", "hansen", "25393203", "kls@gmas.so");


    return 1;

}

