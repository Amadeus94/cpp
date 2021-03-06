#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;



// Exercise 2 - Write a program that converts from miles to km
double miles_to_km(double miles){
	return miles*1.609;
}
//Exercise 3
void testLegalNaming(){
	int i; // legal name
//	CHAR i; // illegal name: Error: 'CHAR' was not declared in this scope 
//	int ?s;	 // illegal name: Error: expected unqualified-id before '?' token
	int this_dog; // legal wtf
//	int 2_karl; // Error: Expected unqualified-id before numeric constant;
	int $dog; // legal
	int This_little_pig;
 // 	int latest thing; // illegal: Error: Expected initializer before 'thing' 
 	int MiniMineMine;
	int the_$12_method;
//	int correct?; //illegal - Expected initializer before '?' token 

}
//Exercise 4
double smaller(int val1, int val2){
	return val1 <val2? val1 : val2;
}
double larger(int val1, int val2){
	return val1 >val2? val1 : val2;
}
double sum (int val1, int val2){
	return val1 + val2;
}
double difference(int val1, int val2){
	return val1-val2;
}
double product (int val1, int val2){
	return val1*val2;
}
double ratio (double val1, double val2){
	return val1/val2;
}


//Exercise 6
bool compare(int num1, int num2){
	return num1<num2;	
}
bool compareTo(string num1, string num2){
	return num1<num2;	
}



//Exercise 9
void StringToInt(){
	map<string, int> numbers; 
	numbers["zero"] = 0;
	numbers["one"] = 1;
	numbers["two"] = 2;
	numbers["three"] = 3;
	numbers["four"] = 4;
	numbers["five"] = 5;
	numbers["six"] = 6;
	numbers["seven"] = 7;
	numbers["eight"] = 8;
	numbers["nine"] = 9;
	numbers["ten"] = 10;
	
	cout << endl << "Enter a spelled out number 0-10" << endl << ">";	
	string chosenNumber;
	cin>>chosenNumber;
	cout << endl;
	// checks if the string is found in the map numbers
	// 	Returns an iterator that is not numbers.end() if its found
	numbers.find(chosenNumber)!=numbers.end() ? cout << numbers[chosenNumber] << endl :  cout << "Key not found" << endl;
}


// Exercise 10
void stringToOperation(){
	 char operation;
	 double num1,num2;
	 cout <<  "Create a operation by providing three values like this: + 10 23.4" << endl  << ">";
	 cin >> operation >> num1 >> num2;
	 cout << endl;
	 switch(operation){
		 case '+':
			cout << num1+num2 << endl; 
			break;	
		 case '-':
			cout << num1-num2 << endl; 
			break;	
		 case '*':
			cout << num1*num2 << endl; 
			break;	
		 case '/':
			cout << num1/num2  << endl; 
			break;	
		 default:
			cout << "that's not valid input" << endl ;

	 }}

int hlpfnc_calculatePennies(int pennies, int nickels, int dimes, int quarters, int halfDollars, int dollars)
{
	return pennies*1+nickels*5+dimes*10+quarters*25+halfDollars*50+dollars*100;
			}
string pluralorNotString(int num, string amountInPlural, string amountInSingular){

		string s = " ";
	if(num==1){
	s+= amountInSingular;
		s+= ", ";
		return s; 	
	}
		s+= amountInPlural;
		s+= ", ";
	return s;
}

// Exercise 11
void WalletToPennies(){
	//Values in pennies --- penny == cent... is the same
//	const int penny = 1;
//	const int nickels = 5;
//	const int dime = 10;
//	const int quarters = 25;
//	const int halfDollar = 50;
//	const int dollar = 100;
	int myPennies, myNickels, myDimes, myQuarters, myHalfDollars, myDollars;
	cout << "Enter the number of pennies you got" << endl;
	cin >> myPennies;
	cout << "Enter the number of nickels you got" << endl;
	cin >> myNickels;
	cout << "Enter the number of dimes you got" << endl;
	cin >> myDimes;
	cout << "Enter the number of quarters you got" << endl;
	cin >> myQuarters;
	cout << "Enter the number of halfDollars you got" << endl;
	cin >> myHalfDollars;
	cout << "Enter the number of dollars you got" << endl;
	cin >> myDollars;
	
	cout << "You have:" << endl << myPennies << pluralorNotString(myPennies, "pennies", "penny")<< endl << myNickels << pluralorNotString(myNickels, "nickles", "nickle")<< endl << myDimes <<
		pluralorNotString(myDimes, "dimes", "dime")<< endl << myQuarters << pluralorNotString(myQuarters, "quarters", "quarter") << endl << myHalfDollars << pluralorNotString(myHalfDollars, "halfdollars", "halfDollar") <<
	       	endl << myDollars << pluralorNotString(myDollars, "dollars", "dollar")<< endl;

// pennies
	cout << "In total: " <<  hlpfnc_calculatePennies(myPennies, myNickels, myDimes, myQuarters,myHalfDollars,myDollars) <<" pennies"<<endl; 

	// Dollars
double s = static_cast<double>(hlpfnc_calculatePennies(myPennies, myNickels, myDimes, myQuarters,myHalfDollars,myDollars))/100;

		cout << "In total: " << s <<"$ dollars"<<endl; 


}

int main(){
	//Exercise 11:
	WalletToPennies();
	// Exercise 2
	cout << "Enter miles to be converted to km" << endl << ">";
	double miles;
	cin >> miles; 
	cout << endl <<  miles << " miles == " << miles_to_km(miles)<< " km" << endl;

	//Exercise 3
	testLegalNaming();
	
	//Exercise 4
	int val1,val2;
	cout << endl << "Enter your first number" << endl << ">\t" ;
	cin >>val1;
	cout << endl << "Enter your second number" << endl << ">\t" ;
	cin >> val2;
	cout << endl;
	cout << "val1\tval2\tsmaller\tlarger\tsum\tdifference\tproduct\tratio" << endl;
	cout << val1 <<"\t" << val2 << "\t" << smaller(val1,val2) << "\t"<< larger(val1,val2) << "\t"<< sum(val1,val2)
	       << "\t"<< difference(val1,val2) << "\t\t"<< product(val1,val2) << "\t"<< ratio(val1,val2) << "\t";

	//Exercise 6
	int num1,num2,num3;
	cout << endl << endl <<  "Enter three numbers to be sorted" << endl << ">";
	cin >> num1 >> num2 >> num3;
	vector<int> v{num1,num2,num3};
	sort(v.begin(), v.end(), compare);
	cout << endl << "The sorted numbers:"<< endl;
	for (int i : v){
		cout << i << endl;
	}

	
	for(int i {0} ; i<v.size()-1; i++){
		cout << v.at(i) << "," ;
	}	
	cout << v.at(v.size()-1) << endl;

	// Exercise 7 
	cout << endl << "Strings: " << endl;
	vector<string> authors= {"Steinbeck", "Hemingway", "Fitzgeral"};
	sort(authors.begin(), authors.end(), compareTo);
	for(string jj: authors){
		cout <<jj<< "\t";
	}

	// Exercise 8
	
	cout << endl << "Choose number to check if it is even " << endl << ">";
	int number;
	cin >> number;
	cout << endl;
	number%2==0 ? cout << "The number " << number << " is even" : cout << "The number " << number << " is uneven"; 
	
	// Exercise 9
	StringToInt();	

	//Exercise 10
		stringToOperation();


}


