#include <iostream>

// Compile errors
//  2 types:
//      Syntax errors: Errors that are grammatically wrong...dothis(7; ... missing matching parenthesuis
//      Type errors: Errors that put wrong type in arguments

int area(int length, int width);
int area(int length, int width);

int main(){
    // Syntax Errors
    //int s1= area(7; // error: ) missing
        // compiler: error: expected ')' before ';' token
    //int s2= area(7) // error: ; missing
        //compiler: error: too few arguments to function 'int area(int,int)' 
        //          error: ; missing
    //Int s3=area(7); // error: Int is not a type 
        // compileError, Error:'Int' was not declared in this scope
        //               error: 'Int' is not a typeh
    //int s4 = area('7); // error: non-terminated character(' missing)
       // Compile error: Warning: character constant too long for its type
       //         error: non-terminated character (' missing)
  ////////////////////////////////////////////////////////////////////////
  //                Type Errors
    //int x0 =arena(7); //error:undeclared function
        // compile error: 'arena' was not declared in this scope 
    //int x1 = area(8); // error: wrong number of arguments
      // Compile error: too few arguments to function 'int area(int, int)'
    //int x2 = area("seven", 2); // error: 1st argument has a wrong type
        // Compile error: Invalid conversion from 'const char*' to 'int' [-fpermissive]
        //                                                                  /-fpermissive flag Downgrade some diagnostics about nonconformant code from errors to warnings. Thus, using -fpermissive will allow some nonconforming code to compile.
        //don't use it unlessy ou know what you are doing                                                                       
}
