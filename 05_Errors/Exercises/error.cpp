#include <algorithm>
#include <math.h>
#include <stdexcept> // invalid_arg
#include <iostream> // cerr
#include <vector>
using namespace std;

// Correct the errors 
double ctok(double c){ // Converts celsius to kelvine
     if(c<273.15){
        throw invalid_argument("It is under 273 celsius.. not possible");
    }
    double k= c+273.15;
    return k;
}



// Exercise 5
//kelvin to celsius

double ktoc(double k){
    
    double c = k-273.15;
    return k;
}

//Exercise 6
double ctofahrenheit(double c) {
    return (9.00/5) *c +32;
}

double fahrenheittoc(double fahrenheit){
     return (fahrenheit-32)/(9.0/5);
    //return (fahrenheit-32)*5/9;

}

// Exercise 7
//      Quadratic equations are of the form
//          a*x^2+b*x+c=0
//
//      To solve thes, one uses the quadratic formula:
//          x=(-b+-sqrt(b^2-4ac))/2a
//
//      If the determinant ie b^2-4ac is less than zero, then it will fail

void QuadraticEquation(double a, double b, double c){
    double determinant = b*b-4*a*c;
    if(determinant<0)
        throw invalid_argument("Determinant is negative ie has no real roots");
     double x1 =( -b+sqrt(determinant))/2*a;
     double x2 =( -b-sqrt(determinant))/2*a;
        
     cout << "x1: " << x1 << endl;
     cout << "x2: " << x2 << endl;

    

}


// Exercise 8
//  Wrute  a origran tgat reads abd stires a serues fi ubtegers ð
//      then compute the sum of the first N integers
//      First ask for N , then read the values into a vector
//      Then vcalculate the sun mof the first N value
//
void storeIntergers(){
    int result{};
    vector<int> integers;

    cout<< "Please enter the number of values you want to sum:" ;
    int numToSum{};
    cin>> numToSum;

    // cin will toggle its failbit incase its not a integer
    if(!cin){
        throw invalid_argument("thats not a int");

    }
    cout<< "Please enter some integers (presse '|' to stop):";
    int numb{};
    for(int i=0; i<numToSum; i++){
        cin>>numb;
        if(!cin)
            continue;
        integers.push_back(numb);
    }
    
    while(cin>>numb){
    if(!cin){
        throw invalid_argument("thats not a int");

    }

    };
    
//exercise 9
    if(integers.size() < numToSum)
        throw invalid_argument("there aren't enough numbers to fulfill your request");

    for(int i: integers)
        result+=i;
        
    
    cout << "Sum of first "<<  numToSum << " numbers (";
    for(int i : integers)
        cout << i << ",";
    cout << "\b " << ") is " << result;
}


void storeDouble(){
    double result{};
    vector<double> doubles;

    vector<double> adjacentDifference;
    cout<< "Please enter the number of values you want to sum:" ;
    double numToSum{};
    cin>> numToSum;

    // cin will toggle its failbit incase its not a integer
    if(!cin){
        throw invalid_argument("thats not a int");

    }
    cout<< "Please enter some integers (presse '|' to stop):";
    double numb{};
    for(int i=0; i<numToSum; i++){
        cin>>numb;
        if(!cin)
            continue;
        doubles.push_back(numb);
    }
    
    while(cin>>numb){
    if(!cin){
        throw invalid_argument("thats not a double");

    }

    };
    

    if(doubles.size() < numToSum)
        throw invalid_argument("there aren't enough numbers to fulfill your request");

    for(double i: doubles)
        result+=i;
        
    
    cout << "Sum of first "<<  numToSum << " numbers (";
    for(double i : doubles)
        cout << i << ",";
    cout << "\b " << ") is " << result;

    for(int i=0; i<numToSum-1;i++){
        double n1 = doubles.at(i);
        double n2 = doubles.at(i+1);
        double differnce = n1 - n2;
        adjacentDifference.push_back(differnce); 
    }

   cout << endl << "differences between adjacent number:" << endl;

   for(double i : adjacentDifference){
        cout << i << endl;
   }
}

   // Exercise 11
   //   Write a program that writes out n fibonacci numbers 
   // And then find the largest fibonacci number that fits an int 

   vector<int> fibonacciNumber(int n){
       vector<int> fibonacciNumbers;
       int tmp1{0}; 
       int tmp2{1};
       int sumOfPreviousTwo{};
       



       for(int i = 0; i<n; i++){
           if(i==0) {
               fibonacciNumbers.push_back(i);
                continue;
           } else if(i==1){
               fibonacciNumbers.push_back(i);
                continue;
           }
           sumOfPreviousTwo = fibonacciNumbers.at(i-1) + fibonacciNumbers.at(i-2);
           
// Create method for finding biggest fibonacci number that fits an int 
          if(sumOfPreviousTwo<0) {
              cout << "You have reached the limit of int" << endl;
              cout << "The last possible integer is held, when n is: " << i << endl;
              cout << "Which is the value: " << fibonacciNumbers.at(fibonacciNumbers.size()-1);
              break; 
          }

           
           fibonacciNumbers.push_back(sumOfPreviousTwo);


      /* for(int i: fibonacciNumbers)
            cout << i << endl; */
   }
       return  fibonacciNumbers;
   }
   


// Exercise 12
//      Bulls and Cows - Guessing Game
//          - vector of four different integers in the range 0-9 
//              - Ok: 1234
//              - Not ok: 1122 -- Has to be different
//         -User
//              - Guess what the four numbers are by repeated guesses
//                  - if numbers are: 1234
//                  - User guesses    1359
//                      - Response from system should be: 1 bull and 1 cow
//                          - Because user got (1 digit right and in right position) - 1 bull
//                          -                  (1 digit right but not in correct position) - 1 cow 
//                  - Game conitnues until user gets four bulls
bool isBull(vector<int> winningNumbers, vector<int> guesses, int index){
    return true;    
}
bool isCow(int number, int guess){
    return true; 
}

bool checkWinningConditionBullsAndCows(vector<int> winningNumbers, vector<int> guesses){
    int isBull=0;
    int isCow=0;
    
    //check is Bull 
    for(int i=0; i<guesses.size();i++){

        if(guesses.at(i)==winningNumbers.at(i))
            isBull++;
        else if(find(winningNumbers.begin(), winningNumbers.end(), guesses.at(i))
                !=winningNumbers.end() && (winningNumbers.at(i)!=guesses.at(i)))
            isCow++; // Cow checks double.. so noit perfect 
    }
    
    cout << endl << "You have " << isBull << " bulls and " << isCow << "cows" << endl; 
   
    if(isBull==4){
    return true;
    }
    return false;
}




    


void BullsAndCows(){
    vector <int> winningNumbers {1,5,6,7};
    cout << "Welcome to Bulls And Cows " << endl << 
            "There are four digits 1-9 like 1234, and you will have to guess the correct digits and position of them" << endl <<
            "Good luck! " << endl << endl;


    cout << "Pick a 4 numbers" << endl;
    while(true){
        vector<int> guessedNumbers;
        for(int guessedNumber=0,i=0; i<4; i++){
            cin >> guessedNumber;
            if(!cin){
                cout << "Sorry that is not possible, try again " << endl; 
                i--;
            }else
                guessedNumbers.push_back(guessedNumber);
            
            
        
        }
 if(checkWinningConditionBullsAndCows(winningNumbers,guessedNumbers)){
            cout << endl << " Congraatz you beat the game ";
            break;


           }
    }
}




void BullsAndCows_v2(){
    vector<int> winningNumbers;
    while(true){
        winningNumbers.clear();
        
    for(int i=0, randomInt; i<4; i++){
        // rand() gives a random integer [0,INT_MAX)
        //      - Can easily manipulate it by modulo 100 etc. then will be 0-99 
        randomInt = rand() % 10; // 09
       winningNumbers.push_back(randomInt);

            
    }
    cout << "Welcome to Bulls And Cows " << endl << 
            "There are four digits 1-9 like 1234, and you will have to guess the correct digits and position of them" << endl <<
            "Good luck! " << endl << endl;


    cout << "Pick a 4 numbers" << endl;
    while(true){
        vector<int> guessedNumbers;
        for(int guessedNumber=0,i=0; i<4; i++){
            cin >> guessedNumber;
            if(!cin){
                cout << "Sorry that is not possible, try again " << endl; 
                i--;
            }else
                guessedNumbers.push_back(guessedNumber);
            
            
        
        }
 if(checkWinningConditionBullsAndCows(winningNumbers,guessedNumbers)){
            cout << endl << " Congraatz you beat the game ";
            break;


           }
    }
}
}

//  week of the day

// Since c++ Doesn't support hash  switch statement you can just hash a string
//  And use that hash 
// ie. constexpr hash function
//  I don't how it works exactly 
    // https://stackoverflow.com/questions/650162/why-the-switch-statement-cannot-be-applied-on-strings
constexpr unsigned int hashstring(const char *s, int off =0 ) {
    return !s[off] ? 5381 : (hashstring(s, off+1)*33) ^  s[off];
}

string whatDay(string str) {
    string result= "Not Found"; 
    // convert string to upper case
    std::for_each(str.begin(), str.end(), [](char & c) {
            c = ::toupper(c);
            });

    switch(hashstring(str.c_str())){

        case hashstring("MON"): 
        case hashstring("MONDAY"):
            result= "Monday";
            break;
        case hashstring("TUE"): 
        case hashstring("TUESDAY"):
            result= "Tuesday";
            break;
        case hashstring("WED"): 
        case hashstring("WEDNESDAY"):
            result= "Wednesday";
            break;
        case hashstring("THU"): 
        case hashstring("THURSDAY"):
            result= "Thursday";
            break;
        case hashstring("FRI"): 
        case hashstring("FRIDAY"):
            result= "FRIDAY";
            break;
    }
    return result;
            // convert string to upper case
            //     std::for_each(data.begin(), data.end(), [](char & c) {
            //             c = ::toupper(c);
            //                 });
            //                
    }


void funDAY(){


    vector<string> days;
    vector<int> day_values;
    int illegalCounter{};
    int sumOfValues;
    cout << "Hello Participant  " ;
    while(true){

          cout <<   "\n Please enter a day, and then a value like this: "
            "\n Tuesday 24  " 
            "\n >>>>> Now you try "
            "\n";

          string day;
          int value;

          cout << "Enter a day" << endl;         
          cin>>day;
          if(!cin){
              cout << "error try again from start " << endl;
              break;
          }
          cout << "Enter a value" << endl;         
          cin>>value;

          if(!cin){
              cout << "error try again from start " << endl;
              break;
          }

          day = whatDay(day);
          if(day=="Not Found"){
              illegalCounter++;
              continue;
            }
          days.push_back(day);
          day_values.push_back(value);

          } 



    cout << endl << "Day\tDay_Values\tIllegal Counter" << endl;
    for(int i =0; i<day_values.size(); i++){
        cout << days.at(i) << "\t" << day_values.at(i) << "\t"<< illegalCounter <<  endl;
    }

    for(int i: day_values)
        sumOfValues+=i;

    cout << "Sum of all values: "  << sumOfValues;
}



int main(){

//    cout<< fahrenheittoc(10); //
//    double c  =0;
//    cout << "celsius to kelvin" << endl << ">"; 
//    cin >> c;
//   /* Exercviise 3
//    * if(c<273.15){
//        throw invalid_argument("It is under 273 celsius.. not possible");
//    }
//    */
//    double k = ctok(c);
//    cout << endl << k << '\n'; 

    // Exercise 7
//    QuadraticEquation(1,17,1);
//
//    Exercise 8
      //storeIntergers();
      //
      //Exercise 10
    //  storeDouble();
    //
    //
    //  Exercise 11

    // Instead of a container variable I just added the method directly
    //  - And it worked lol
   // for(int i : fibonacciNumber(49)){
   //     cout << i << endl; 
   // }
   // cout << endl << "Highest int possible: "  <<  INT_MAX;
   //
   // Exercise 12
//    BullsAndCows();
//    Exercise 13
//        BullsAndCows_v2();

    //Exercise 14
    // No idea if understood this one correct
    funDAY();
}
