struct Function : Shape{
    Function(
            Fct f, 
            double r1, 
            double r2, 
            Point orig, 
            int count = 100,
            double xscale = 25, 
            double yscale = 25
            );
};

Function:Function(
            Fct f, 
            double r1, 
            double r2,   // start of graph ie -100 pixels perhaps?  tooo 100 ppixels .. r1.r2.
            Point orig,  // Mid of graph
            int count = 100,
            double xscale = 25,  // Size it up ...
            double yscale = 25
            )
    {
      if(r2-r1<=0)
          error("Bad graphing range");
      if(count<=0)
          error("non-positive graphing count");
      double dist = (r2-r1)/count;
      double r = r1;
      for(int i = 0; i<count;++i){

        add(Point{xy.x + int(r*xscale), xy.y - int(f(r)*yscale)});
        r+=dist;
      }


    }

// Sloping Cosinus
// <cmath>
double sloping_cos (double x){
    return cos(x) + slope(x);
}


//driver code
Function s4{sloping_cos, r_min, r_max, orig, 400,30,30};  // Draws a  sloping func 
// .... set color +  winattach code




             }


// Lambda Expressions
//  It can get tedioyus to define a function just to have it to pass as an argument to a Function 
//  Lambda Expressions defines something that acts as a function in the argument position where it is needed
//      Ie an uinnamed function defined right where it is needed as an argument
//      [] is called the lambda introducer
//      after the lambda introducer it specifies what arguments are required (the argument list) and what actions  are
//      to be performed (the function body) 
//      The return type can be deduced from the lambda body 

Function s5{
    [](double x){return cos(x) +slope(x);}, // lambda expression  [](double args) 
     r_min, r_max, orgi, 400,30,30};




//      The return type can be deduced from the lambda body 
//          for instance in previous  "return cos(x) +slope(x);" would yield double
//      However, we can also make it explicit 
   Function s5([](double x) -> double{return cos(x) + slope(x); },
           r_min,r_max,orig,400,30,30};
               
// Specifying the return type for a laambda expression is rarely necessary
//  The main reason for that is that lambda expressions should be kept simple to avoid it becoming a source of 
//      errors & confusion
//  Ie if  a piece of code does something significant, it should be given a name and probably requires a comment to be
//  comprehensible to people other than the original programmer.
//  Best practices:
//      Use named functions for anything that doesn't easilyu fit on a line or two
// The lambda introducer can be used to give the lambda expressions access to local variables....
//

