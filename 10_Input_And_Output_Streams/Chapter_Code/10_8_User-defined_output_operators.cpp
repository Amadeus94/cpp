
// Defining the output operator for a given type is typically trivial << 
    // Problem lies mostly in different people have different tastes in design of output

// Often a good idea to << for a user-defined type ... << is basically "toString()"
    // makes it trivial to write out objects of the type during debugging and early develpoment 
    // later in development may provide a more sophiisticated << that is formatted 

// Example:     ostream& operator<<(ostream& ios, const Date& d){ return os << "(" << d.year;}
    //          ^^ Keeping ostream as reference return type is how we chain ostream  and pass along so you can chain output operations .. cout << d1 << d2  
    //      Same operations:
    // cout << d1 << d2
    // cout operator<<(cout,d1)<<d2;
    // cout operator<<(operator<<(cout,d1), d2);

