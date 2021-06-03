#include <limits> // gets the double_MAX
#include <float.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Median 
	// A number so that exactly as many elements come before it in the sequence as come after it 
	// Hint: doesn't need be a part of the sequence
        // Equal Number = %2==0 then take number /2 index and index +1  and use average of those as media
        


bool compare(double num1, double num2){
    return num1<num2;
}

//Exercise01
double median(vector<double> container){ 
   sort(container.begin(), container.end(), compare); 
   double median;
   //Equal numbers
   if(container.size()%2==0){
        double num1 = container.at((container.size()/2)-1); 
        double num2 = container.at((container.size()/2));
        median = (num1+num2)/2;
   }else
       median =container.at(container.size()/2);   
   return median; 
}



//Exercise02
    //Read a sequnece of double values into a vector
        // each value as the distance between two cities along a given route
   //1. Compute and print the total distance ( the sum of all distances)
   //2. Find and print the smallest and greatest dsistance between two neighboring cities
   //3. Find and print the mean distance between two neighboring cities

//helper function for ex02
double totalDistance(vector<double> v){
    double sum{0};
    for(double i:v){
        sum+=i;
    }
    return sum;
}

double smallest(vector<double> v){
    sort(v.begin(), v.end(), compare);
    return v.at(0);
}


double greatest(vector<double> v){
    sort(v.begin(), v.end(), compare);
    return v.at(v.size()-1);
}

double meanDistance(vector<double> v){
    return totalDistance(v)/v.size();
}

// Exercise 04
    // Write a program to play a numbers guessing game
        // User thinks of a number between 1-100
        // Program asks to figure out what the number is : "Is the number you are thinking of less than 50?"
        // Questions should find number within 7 questions 
void GuessingGame(){
    cout << endl << "=====================================================================" << endl<< 
        "\t\t Welcome to the Guessing Game" << endl << endl ; 
    int pickedNumber{101};
    while( pickedNumber<1 || pickedNumber>100){
        cout << endl <<  "Please pick between 1-100 " << endl << ">";
        cin >> pickedNumber;
    }
    cout << endl;

    int counter{0};
    int highest{100};
    int lowest{0};


    for(int computerGuess{50} ; computerGuess!=pickedNumber;counter++ ){

        cout << endl << "Is the number less than " << computerGuess << "?" << endl<< ">"; 
        string answer;
        cin>>answer;

        transform(answer.begin(), answer.end(),answer.begin(), ::toupper);

        if (answer=="NO") { 
            lowest=computerGuess;
            computerGuess+=(highest-computerGuess)/2; 

        }

        if(answer=="YES"){
            highest=computerGuess;
            computerGuess=(computerGuess+lowest)/2;
        }
    }
    cout << endl << "=========================================" << endl << 
        "\t\t FINISHED IN  " <<  counter << " Guesses" ;





}

//Exercise05
//  Weirdly enough a CIN produces an automatic newline ... 
void calculator(){
    double num1, num2;
    char oper;
    string str;

     
    while(true){
        cout << "enter a math equation +-%/ like: 2+4" << endl;

    
//.similar for seconds
// My first solution:
//  It creates a new line after ie 2+4 
//                                 = 4 
//                                 Instead of 2+4=6
//                                 Above is created a new way by just getting the string instead, and then parse the
//                                 string 

        cin >>num1 >> oper >> num2;
        switch(oper){

            case '*':
                cout << "\b=" << num1 * num2 << endl;
                break;
            case '/':
                cout << "="<<   num1 / num2<< endl;
                break;
            case '+':
                cout << "="<<num1 + num2<< endl;
                break;

            case '-':
                cout << "="<<num1 - num2<< endl;

                break;
            default: 
                cout<< "Sorry that is not possible";
        }
        cout << endl;
   
    }
}

//Exercise 06
//  string to value ... cin>> "seven" is 7 
//      Gives 1-10 values and if not valid ... gives -1
int stringToInt(string number){
    vector<string> numbers{"zero", "one","two","Three","four", "five", "six","seven", "eight", "nine","ten"};
    for(int i =0; i<numbers.size();i++){
        if(number==numbers.at(i)) 
            return i;
}

    return -1;
}


// Exercise 06
//  Modify the calculator from exercise 05
//      To accept only single-digit numbers written as either digits or spelled out


void calculatorIntOrString(){
    string numb1, numb2;
    int num1{-1}, num2{-1};
    char oper;
    string str;
        

    // Allowed options
    vector<string> allowedStringNumbers{"zero", "one","two","Three","four", "five", "six","seven", "eight", "nine", "0","1","2","3","4", "5","6", "7","8","9"};
    while(true){
        cout << "enter a math equation +-%/ like: 2+4" << endl;
        cin >>numb1 >> oper >> numb2;
        // check if it is a string
        for (int i =0; i<10; i++){
            if(numb1==allowedStringNumbers.at(i)) num1=stringToInt(allowedStringNumbers.at(i));
            if(numb2==allowedStringNumbers.at(i)) num2=stringToInt(allowedStringNumbers.at(i));
        }
        for(int i=10; i<allowedStringNumbers.size();i++){
            if(numb1==allowedStringNumbers.at(i)) num1=i-10;
            if(numb2==allowedStringNumbers.at(i)) num2=i-10;
        }
        cout << "The chosen numbers are " << endl << num1 << oper << num2;

        if(num1 == -1 || num2 ==-1) continue;
        

        switch(oper){

            case '*':
                cout <<  num1 * num2 << endl;
                break;
            case '/':
                cout << "="<< num1 / num2<< endl;
                break;
            case '+':
                cout << "="<<num1 + num2<< endl;
                break;

            case '-':
                cout << "="<<num1 - num2<< endl;

                break;
            default: 
                cout<< "Sorry that is not possible";
        }
        cout << endl;
   
    }
}

//Exercise08
//  Old Story: An emperor wanted to tank the inventor off game of chess and asked the inventor to name his reward
//             The Inventor asked for
//                  1 grain of rice for the first square 
//                  2 for the second
//                  4 for the third ... and so on.. doubling for each of the 64 squares
//             Calculate how many squares are required to give the inventor at least 
//                  1000 grains
//                  1,000,000 grains
//                  1,000,000,000 grains
double grain(double grainsToSquare){

   double  currentGrains {0};
   cout << "Emperor Chess Game" << "with " << grainsToSquare << endl;

  
   double square = 0;
           // this should be changed to 64.. but testing double 
   for(; square<100000; square++){
      if(currentGrains < grainsToSquare){
        currentGrains += pow(2,square); 
        cout << endl << "Current Square : " << square << endl;
        cout << endl << "Current amount of grains : " << currentGrains << endl;
      }else{
          break;
      }
    cout << endl;        
     
   }
   return square;

}

// Exercise 10
    //  Use a switch  statement to solve this
    //  Machine should give random answer
    //      Build a vector sequence of numbers to be used ... ie {1,2,1,3,2,3,2,1}
    //      Allow users choose the "machines" answer ... choose 1-50 .. what the robot will do

bool winningCondition(int i, int j){
    
    return 1;
}

int ValueToRPS(string value){
    if(value == "rock" || value=="0")
        return 0;
    else if(value == "paper"|| value=="1")
        return 1;
    else if(value == "scissor"|| value=="2")
        return 2;
    return -1;
} 

string numberToRPC(int value){
    if( value==0)
        return "rock";
    else if( value==1)
        return "paper";
    else if(value==2)
        return "scissor";
    return "error";
}

bool winOrLose(int player, int robot){
    return true;   
}


// 100 lines --- this could be massively refactored
void rockPaperScissors(){
    vector<string> robotAnswer{"0","1","2","0","2","1","0","1","1","2"};
    // Switch statement where 
    //  1 = rock
    //  2 = paper
    //  3 = Scissor
    cout << "Rock Paper Scissor Game" << endl;
    cout << "Pick rock paper or scissor " << endl << ">";
    string humanPick;
    cin >> humanPick;
    cout << "you picked " << humanPick << endl;
    int humanValue =ValueToRPS(humanPick);
    cout << endl << "Pick a number for the computer between 0-9" << endl  << ">" ;
    int robotPick;
    cin >> robotPick;
    string conv = robotAnswer.at(robotPick);

    int robotValue = ValueToRPS(conv);
    cout << "You chose " << robotPick<<  " for the number which equals to a " << robotValue << endl; 
    cout << "Player: " << humanPick << endl
        << "Robot: " <<  numberToRPC(robotPick) << endl
        << "==================================================" << endl;

    // 0 rock
    //      0 - draw
    //      1 - lose
    //      2 - win 
    // 1 paper
    //      0 - win
    //      1 - draw
    //      2 - lose
    // 2 scissor
    //      0 -  lose
    //      1 - win
    //      2 - draw
    // modulo 3 
    // geri tað sláviskt

    if(humanPick == "rock"){
        switch(robotValue){
            case 0:
                cout << "It is a Draw - Rock draws Rock"  ;
                break;
            case 1: 
                cout << "It is a Loss - Rock loses to Paper";
                break;
            case 2:
                cout<<  "It is a win - Rock beats scissor" ; 
                break;
        }}else if(humanPick == "paper"){
            switch(robotValue){
                case 0:
                    cout << "It is a win - paper wins  Rock"  ;
                    break;
                case 1: 
                    cout << "It is a draw - paper draws Paper";
                    break;
                case 2:
                    cout<<  "It is a loss - paper loses to  scissor" ;
                    break;
            }
        }else if(humanPick == "scissor"){
                switch(robotValue){
                    case 0:
                        cout << "It is a loss - scissor loses to  Rock"  ;
                        break;
                    case 1: 
                        cout << "It is a win scissor -  scissor beats Paper";
                        break;
                    case 2:
                        cout<<  "It is a draw- scissor draws scissor" ;
                        break;
                }}else  {
                    cout << "sorry that is not possible" << endl;





                    //    switch();

                }
}


// Exercise 11
//  Find all prime numbers between 1-100
//      Prime definition: A number that is only  divisible by itself:
//          13/13 =  ;  1*13  -- only a pair that at the product is equal the prime .. 1*13 *11
//              List:  2,3,5,7,11,13,17,19...
//      // how ?
//      One way of doing this is to write a function that will check if a number is prime
//          using a vector of primes IN ORDER
//              //
//          if a number is prime (i.e. see if the nuymber can be divided by a prime number smaller than itself) ð
//      Using a vector where primes[0] = 2 primes[1] = 3,  primes[2] = 5
// Consider 2 to be the first prime

int primes(){
    vector<int> primeNumbers = {2};
    bool isPrime=true;
    for(int i=3; i<100 ; i++){
        for(int j=0; j<primeNumbers.size();j++){
            if(i%primeNumbers.at(j)==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime) primeNumbers.push_back(i); 
        isPrime=true;

    }

    for (int i: primeNumbers) cout << i << endl;
    return 1;
}


// exercise 12
// Modify exercise 11 to take an input value max and then find numebr from 1 to max
int primes(int max){
    vector<int> primeNumbers = {2};
    bool isPrime=true;
    for(int i=3; i<max ; i++){
        for(int j=0; j<primeNumbers.size();j++){
            if(i%primeNumbers.at(j)==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime) primeNumbers.push_back(i); 
        isPrime=true;

    }

    for (int i: primeNumbers) cout << i << endl;
    return 1;
}




// Exercise 13
void findprime_SieveOfEratosthenes(){
    vector<int> v;
    for (int i=2; i<101;i++){ //100 inclusive
        v.push_back(i);
    }




    for(int i=0; i<v.size(); i++){
        for (auto j = v.begin()+i+1; j != v.end(); ++j) {
            // Don't understand exactly why this did work when I reversed *j and v.at(i) .. thought would be the other
            // way around ... need to recheck 
            if ((*j) %  v.at(i)  == 0) {
                v.erase(j);
                j--;
            }
        }
    }

for (int i : v ) cout << i << endl;
}


// Exercise 13
vector<int> findprime_SieveOfEratosthenes(int max){
    vector<int> v;
    for (int i=2; i<max+1;i++){ //100 inclusive
        v.push_back(i);
    }




    for(int i=0; i<v.size(); i++){
        for (auto j = v.begin()+i+1; j != v.end(); ++j) {
            // Don't understand exactly why this did work when I reversed *j and v.at(i) .. thought would be the other
            // way around ... need to recheck 
            if ((*j) %  v.at(i)  == 0) {
                v.erase(j);
                j--;
            }
        }
    }

//for (int i : v ) cout << i << endl;
    return v;
}


// Exercise 15 
//  Write a program that takes an input n that provides the n first primes
//      n=3  :  2,3,5
void getPrimes(int n){

    vector<int> v = findprime_SieveOfEratosthenes(1000);

    vector<int> primes(v.begin(), (v.begin()+n));

    for(int i: primes) cout << i << endl;
}


// Exercise 16  - Find the Mode
    // A mode is the value with the highest frequency of occurrence in the vector 

template <class myType>
bool compareAll(myType a, myType b) {
    return a<b;
    //return (a>b?a:b) // online...
}

bool sortInt(int num1, int num2){
    return num1<num2;
}
bool compareString(string s1, string s2){
    return s1<s2;
}



template <class myType>
void getMode(vector<myType> v){
    // used for ints
    //sort(v.begin(), v.end(), compare);
    sort(v.begin(), v.end(), compareString);
    vector<myType> result;
    for(myType i: v) cout << i << endl;
    int counter=1;
    int largest=0;
    int index =0; 
    for(int i=1; i<v.size();i++){
        if(v.at(i)==v.at(i-1)){
            counter++; 
        }else{ 
            if(counter>largest){
                largest=counter;
                index=i-1;
            }
                counter=1;
        }
    }
   // cout << "The number with he higest frequency is: " << v.at(index)
    //     << endl << " and occurs: "  << largest << endl;

    cout << "Mode: " << v.at(index) << ", frequency: " << largest << endl;
    
}





//Exercise 17
// Write a program that finds the 
//  min, max, mode of a sequence of strings
void analyzeStrings(vector<string> s){
    getMode(s);
    sort(s.begin(), s.end(), compareString);
    cout << "smallest: " << s.at(0) << endl;
    cout << "largest: " << s.at(s.size()-1) << endl;
}

void smallest(vector<string> v){
    //sort(v.begin(), v.end(), compare);
}


//Exercise 18
//  write a program to solve quadratic equations
//      ax^2+bx+c=0

void solveQuadraticEquation(double a, double b, double c){
   //Formula is: x=(-b+-sqrt(b^2-4ac))/2a
                        //b^2

   double discriminant = b*b-4*a*c;
   // Two solutions if discriminant is positive
   if(discriminant>0){
       double x1 = (-b+sqrt((b*b)-4*a*c))/2*a;
       double x2 = (-b-sqrt((b*b)-4*a*c))/2*a;
       cout << "Two real roots: " << endl << 
           "x1: " << x1 <<
           "x2: " << x2 << endl;
    }else if(discriminant==0){
       double x1 = (-b-sqrt((b*b)-4*a*c))/2*a;
       cout << "One real root: " << endl << 
           "x1: " << x1 <<endl;
        
    } else{//negative
        double x1 = (-b+sqrt((b*b)-4*a*c))/2*a;
        double x2 = (-b-sqrt((b*b)-4*a*c))/2*a;
        cout << "Two non-real roots: " << endl << 
            "x1: " << x1 <<
            "x2: " << x2 << endl;
    }

   }   





    // Exercise 19
         //  Enter a set of name and value pairs. "Joe 17" "Barbara 22" 
         //     For each pair add 
      //          the name to a vector called names
      //          the number to a vector called scores
      //  Terminate input with NoName 0
      //  Check hthat each name is unique  and terminate with an error message if a name is entered twice
      //
      //  Write out all the names and scores pairs one per line


void nameScorePair(){
    vector<string> names;
    vector<int> scores;

    string name;
    int score;

    while(true){
        cout << "Enter a name and pair value \"Barbara 22\"" << endl << ">";
        cin >> name >> score;
        if(count(names.begin(), names.end(), name)){
            cout << endl << "Sorry that name is already entered, please enter another" << endl;
        }else if(name=="NoName" && score==0){
            cout << endl << "The program has stopped.. thanks for using karl enterprise programs" << endl;
            break;
        }else{
            names.push_back(name);
            scores.push_back(score);
        }

    }
    cout << "These are the name-value pairs entered:" << endl;
    for (int i=0; i<names.size(); i++){
        cout << names.at(i) << ": " << scores.at(i) << endl; 
    }

}



// Exercise 20a
void nameScorePair(vector<string> &names, vector<int> &scores){
    string name;
    int score;

    while(true){
        cout << "Enter a name and pair value \"Barbara 22\"" << endl << ">";
        cin >> name >> score;
        if(count(names.begin(), names.end(), name)){
            cout << endl << "Sorry that name is already entered, please enter another" << endl;
        }else if(name=="NoName" && score==0){
            cout << endl << "The program has stopped.. thanks for using karl enterprise programs" << endl;
            break;
        }else{
            names.push_back(name);
            scores.push_back(score);
        }

    }
    cout << "These are the name-value pairs entered:" << endl;
    for (int i=0; i<names.size(); i++){
        cout << names.at(i) << ": " << scores.at(i) << endl; 
    }

}


// Function to print the
// index of an element
template <class myType>
int getIndex(vector<myType> v, myType K)
{
    auto it = find(v.begin(), v.end(), K);
 
    // If element was found
    if (it != v.end()) 
    {
     
        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    else {
        // If the element is not
        // present in the vector
        return -1;
    }
    return -1;
}


//Exercise 20b
void nameToScore(vector<string> names, vector<int> scores){
     
    string name;
    int index;
    while (true){
       cout << "enter a name to find out score" << endl;
        cin >> name;
        index =  getIndex(names, name);
        if(index!=-1) cout << scores.at(index) << endl;
        else if(name=="NoName") break;
        else cout << "not found" << endl;
       
    }

}


//Exercise 21
void scoreToName(vector<string> names, vector<int> scores){
     
    int score;
    int index;
    while (true){
       cout << "enter a score to find out the name" << endl;
        cin >> score;
        index =  getIndex(scores, score);
        if(index!=-1) cout << names.at(index) << endl;
        else if(score==-1) break;
        else cout << "not found" << endl;
       
    }

}

int main(){
//    //Exercise01 - was only the dry this questiosn 
//    //Exercise02  - print median
//    vector<double> cont {1,2,3,4,5,6,7,8,9,10};
//    cout << median(cont) << endl;
//    
//    //Exercise 03 
//    cout <<  totalDistance(cont) << endl;
//    cout <<  smallest(cont) << endl;
//    cout <<  greatest(cont) << endl;
//    cout <<  meanDistance(cont) << endl;
//
//    //Exercise04
//    GuessingGame();
//
//
//    //Exercise05
//    calculator();
//      
//    //Exercise06
//    int chosenNumber{-1}; 
//
//    do{
//
//    cout << "Pick a number between \"zero\" and \"ten\"" << endl;
//    string numb;
//    cin>>numb;
//    chosenNumber = stringToInt(numb);
//    chosenNumber ==-1? cout << endl << "That is not valid ... try between one to ten" << endl :cout << endl <<  "The number you picked was " << chosenNumber << endl;
//    }while(chosenNumber==-1);

    //Exericse07
//calculatorIntOrString();
//

    //Exercise08
//    int square = grain(1000); 
//    grain (1000000);
//    grain (100'000'000);
//    cout << "The final square: " << square;
//
    //Exercise09
        // Calculate the maximum number that a int can contain .. 
            // won't fit an int or a double
//    int max = INT_MAX;
//    double maxdb = numeric_limits<double>::max();
//    cout << "int : " << INT_MAX << endl;
//    cout << "double: " << DBL_MAX << endl;
//    double grainsdobule = grain(max);
//    double grainsdouble = grain(maxdb);
//    
//    
//    cout << "The maximum amount of squares for int before overflow: " << grainsdobule << endl; // 31 
//    cout << "The maximum amount of squares for double before overflow : " << grainsdouble<< endl; // 1024
//

      
    //Exercise 10
//    rockPaperScissors();

    // Exercise 11 
//    primes();



    // Exercise 12 

//    primes(1000);

        // Exercise 13
//    findprime_SieveOfEratosthenes();

    // Exercise 14
//    findprime_SieveOfEratosthenes(1000);

    // Exercise 15
//    getPrimes(3);

   // exercise 16
  //  vector<int> numbers{1,2,21,214,1,24,21,123,123,123,243,1232,3,213312,12,3,3,13,21,31,23,23,32,13,213,2,3,123,123,1231,23,21,123,21,3,123,12,3,123};

    //getMode(numbers);
    // exercise 17
//    vector<string> tysss{"1","hi", "hello","hello","hello","hello","hello","hello","hello","hello","hello","hello","hello","hello", "no"};
//
//    analyzeStrings(tysss);
//
        //Exercise 18   
//    solveQuadraticEquation(-1,2,-3);

        //Exercise 19
     //   nameScorePair();

     //Exercise 20
     vector<string> names;
     vector<int> scores; 
     
     nameScorePair(names, scores);
     nameToScore(names, scores);

     // Exercise 21
     scoreToName(names, scores);



     

}
