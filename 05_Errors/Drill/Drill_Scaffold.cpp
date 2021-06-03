#include "..\..\Bjarnes_Standard_Header\std_lib_facilities.h"



int main() {
    try{
        //All code should go here when scaffolding through the drill
        // 1
        //cout << "Success!\n";
        //Cout << "Success!\n";
            // Cout was not declared in this scope 
        // 2
        //cout << "Success!\n";
/*      cout << "Success!\n;
        //       warning: missing terminating " character
        cout << "Success!\n;
                 ^
                     Drill_Scaffold.cpp:13:17: error: missing terminating " character
                     cout << "Success!\n;
                 ^~~~~~~~~~~~
                     Drill_Scaffold.cpp: In function 'int main()':
                     Drill_Scaffold.cpp:113:5: error: expected primary-expression before '}' token
    }catch(exception& e){

*/
                
//        //3
       //   cout << "Success" << "!\n";
     //   cout <<"Success" << !\n
            // Error \  stray in the program
            // "n" was not declared in this scope
            //
//        // 4 
       // cout << "Success" << '\n';
     //   cout << success << '\n';
        // success was not declared   in this scope
//        
//        // 5 
//        string res=7; // Conversion from int to non-scalar type std::string 
//        vector<int> v(10);
//        v[5]=res; // Cannot convert std::__cxx11::string to int
//        cout << "Success!\n";

//        int res=7; 
//        vector<int> v(10);
//        v[5]=res;
//        cout << "Success!\n";
//
//
//        // 6 
//        vector<int> v(10);
//        v[5] = 7;
//        // no match for call to '(Vecto<int>) (int) 
//        if(v(5)!=7) cout "Success!\n"; // Expected ; before string constant 
//        
//        vector<int> v(10);
//        v[5] = 7;
//        // no match for call to '(Vecto<int>) (int) 
//        if(v[5]==7) cout << "Success!\n"; // Expected ; before string constant 
//


        // 7 
        // cond was not declared in this scope 
//        if(cond)  cout << "Success!\n" ; 
//        else cout << "Fail!\n";
//        
//         bool cond = true;
//         if (cond) cout << "Success!\n";
//         else cout <<"Fail!\n";

//        // 8  - No error just logic error
       // bool c=false;
//        bool c=true;
//        if(c) cout << "Success!\n" ;
//        else cout << "fail!\n";
//        
//        // 9
//        // Warning: Missing temrinating " character
//        // Error: Terminating " Character
//        string s="ape;
//        // error: boo was not declared in this scope
//        boo c ="fool" <s; 
//        // error: c was not declared in this scope
//        if(c) cout << "Success!\n";
//
//        string s="ape";
//        bool c =true; 
//        if(c) cout << "Success!\n";


        // 10 - only logic error
        //string s="ape";
//        string s = "fool";
//        if(s=="fool") cout <<"Success! \n";


        // 11 
//        string s = "ape";
//        // error: no match for 'operator<' 
//        if(s=="fool") cout < "Success!\n";

        //string s = "fool";
        //if(s=="fool") cout << "Success!\n";



//        // 12 
//        string s = "ape";
//        //error: could not convert std::operator+ 
//        //error: no match for <operator
//        if(s+"fool") cout < "Success!\n";

//        string s = "ape";
//        //error: could not convert std::operator+ 
//        //error: no match for <operator
//        if("ape") cout << "Success!\n";


//
//        // 13 
//         vector<char> v(5);
//        // infinite loop .. and actually prints the success.. when it shouldn't
//        //      I guess its some kind of strange compiler setting... this is by far the weirdest one 
//        for(int i=0; 0<v.size(); ++i); cout << "Success!\n"; 


//       vector<char> v(5);
//        // infinite loop .. and actually prints the success.. when it shouldn't
//        //      I guess its some kind of strange compiler setting... this is by far the weirdest one 
//        for(int i=0; i<v.size(); ++i) cout << "Success!\n"; 
//

//
//        // 14 
    //    vector<char> v(5);
    //    // empty loop body
    //    for(int i=0; i<=v.size(); ++i); cout << "Success!\n"; 
      //  for(int i=0; i<=v.size(); ++i) cout << "Success!\n"; 
//
//        // 15  - found no error  - but funny way to prijnt a string
//                  Looked online, and of course... it only printed 6 characters instead of all.. so to fix this use
//                  v.size()
//        string s = "Success!\n";
//        for(int i=0; i<6; ++i) cout << s[i];
//        for(int i=0; i<s.size(); ++i) cout << s[i];
//
//
//        // 16 
        //error: then was not declared
   //     if (true) then cout<<"Success!\n"; else cout << "fail!\n;";
   //     if (true) cout<<"Success!\n"; else cout << "fail!\n;";
//
//        // 17 
//       int x = 2000;
//       int c = 2000;
//      // char c = x; 
//       // result of comparing a comparing a character to an integer is always false
//       if(c==2000) cout << "Success!\n";
//
////
//        // 18 -- Works but.. still risky by not using size  
//                  ie using magic constants as arg = bad
//        string s= "Success!\n";
//     //   for(int i = 0; i<10; ++i) cout << s[i];
//          for(int i = 0; i<s.size(); ++i) cout << s[i]; 
////
//        // 19 
        // error: missing tempalte arguments before v
        // error: v was not declared in this scope
     //   vector v(5);
     //   vector<int> v(5);
     //   for(int i = 0; i<=v.size();++i); cout <<"Success!\n";
//
//        // 20  - logic error 
//        int i =0;
//        int j =9;
//     //   while(i<10) ++j;  // infinite loop .. i always 0 so will always be lower than 10 
//        while(i<10)++i;
//        if(j<i) cout << "Success!\n";
//
//        // 21 
 //       int x = 2;
 //       int d= 4/(x-2); // Integer division ..  error prone
 //                               // Did not give even error eventhough divide by zero...
 //                               // 5/(2-2) = 5/0 ; 
 //       
 //       if(d==(2*x+0.5))
 //           cout << "Success!\n";
 //      
//        int x = 4;
//        int d= 9/(x-2);
//       
//        int condition =2*x*.5;  // no magic constants
//        if(d==condition)
//            cout << "Success!\n";
//

        //22    
  //      string<char> s="Success!\n"; // not how its done lol
            // error: 'std::__cxx11::string' {aka 'std::__cxx11::basic_string<char>'} is not a template string<char> s
 //       string s = "Success!\n";
 //       for (int i=0; i<=s.size(); ++i) 
 //           cout << s[i];
////        
//
//        // 23 
//        int i = 0;  //  error: 'j' was not declared in this scope 
//        while(i<100) ++j;
//                if(j<i) cout <<"Success!\n";
//
//        int i = 0;
//        int j = 50;
//        while(i<100) ++i;
//        if(j<i) cout <<"Success!\n";
//
//
////        // 24 
//        int x=4;
//      //  double d= 5/(x-2); // integer division
//        double d= 5.0/(x-2); // integer division
////        if(d=2*x+0.5) // gives success because its over 0 ... 
////                              uses assignment instead of comparison
////                           and uses + instead of /
//
//        double cond = 1.25*x*.5;
//        if(d==cond)
//            cout<< "Success!\n";
//
////      int x=4;
//        double d= 5/(x-2);
//        if(d=2*x+0.5) 
//            cout<<< "Success!"\n";
//
//
//        // 25 
        //  error: unable to find string literal operator 'operator""M' with 'const char [10]', 'long long unsigned int' arguments
       // cin<<"Success!\n";
 //       cout<<"Success!\n";
//
//"
//        
//
//
//        keep_window_open();
//        return 0;
    }catch(exception& e){
        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }

    /*catch(excepion& e){
        cerr << "Ooops: Unknown exception! \n";
        keep_window_open();
        return 2;


        */

}
