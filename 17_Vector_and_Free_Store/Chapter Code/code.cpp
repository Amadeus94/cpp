

//17.2 Vector Basics

vector<double> age(4); // Create a vector with 4 elements of type double
age[0] = 0.33;
age[1] = 22.0;
age[2] = 27.2;
age[3] = 54.2;

class vector{ // problem? not extendable .. when push..
    int size, age0,age2,age3;
    .../
        
}




// A very simplified vector of double (like vector<double> ) 

class vector{
    int sz; // size
    double* elem;   // pointer to the first element (of type double)
public:
    vector(int s);  //constructor: allocate s doubled
                            // let elem point to them 
                            // store s in sz
    int size() const {return sz;}  // the current size 
