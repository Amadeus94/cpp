#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <sstream>
#include <iterator>
using namespace std;

// While loop  
// 	Reads two ints and then prints them ; exits the program when a "|" is used
void drill01(){
	cout << "Enter two integers and they will be printed: " << endl;
	int i,j;
	while(cin>>i>>j) cout << i << " " << j << endl;	
}

//Change the program to write out the smaller value is folowed by the smaller of the numebr and the larger value is: 
void drill02(){
	
	cout << "Enter two integers to find out which is larger and smaller: " << endl;
	int i,j;
	while(cin>>i>>j) i<j? cout << endl << "The smaller value is: " << i << endl << "the larger value is " << j << endl: cout << endl << "The smaller value is: " << j << endl << "the larger value is " << i << endl;	
	
}

// Add the option to say that they are equal --- if they're equal
void drill03(){
	
	cout << "Enter two integers to find out which is larger and smaller: " << endl;
	int i,j;
	while(cin>>i>>j){
	if(i == j) cout << "They are equal " << endl;
	else i<j? cout << endl << "The smaller value is: " << i << endl << "the larger value is " << j << endl: cout << endl << "The smaller value is: " << j << endl << "the larger value is " << i << endl;	
	}	
}

//use double instead of int 
void drill04(){
	
	cout << "Enter two doubles ie floating point numerals to find out which is larger and smaller: " << endl;
	double i,j;
	while(cin>>i>>j){
	if(i == j) cout << "They are equal " << endl;
	else i<j? cout << endl << "The smaller value is: " << i << endl << "the larger value is " << j << endl: cout << endl << "The smaller value is: " << j << endl << "the larger value is " << i << endl;	
	}	
}

//Say it is "almost equal" if it is within 1/100 of each other  
void drill05(){
	double value =0.0;
	cout << "Enter two doubles ie floating point numerals to find out which is larger and smaller: " << endl;
	double i,j;
	while(cin>>i>>j){
		value = i-j;
	if(i == j) cout << "They are equal " << endl;
	else {
	       	i<j? cout << endl << "The smaller value is: " << i << endl << "the larger value is " << j
		       	<< endl: cout << endl << "The smaller value is: " << j << endl << "the larger value is " << i << endl;	
	if(abs(value) < (1.00/100.00)) cout << "they are almost equal" << endl; 
		
	}}}

bool doubleSort(double num1, double num2){
	return num1<num2;
}

// Try reading just one double each time around
// 	Define two variables to keep track of which is the smallest and which is the largest value you havve seen so far
// 	Each time through the loop print the the value entered 
// 		if its the smallest so far after the numbner
// 		if its the largest so far write after the number  
void drill06(){
	vector<double> numbersEntered;
	double  smallest;
	double largest;
	cout << "Enter one double ie floating point " << endl;
	double i;
	while(cin>>i){
		numbersEntered.push_back(i);
		sort(numbersEntered.begin(),numbersEntered.end(), doubleSort);
		smallest = numbersEntered.at(0);
	        largest = numbersEntered.at(numbersEntered.size()-1);
	       	cout << endl << "The smallest value is: " << smallest;
		if(numbersEntered.size() ==1 || numbersEntered.at(1) > i)
		  cout << ", and is the smallest number entered so far" ;	
		cout << endl << "the largest value is " << largest;
		if(numbersEntered.size() ==1 || (numbersEntered.at(numbersEntered.size()-2) < i))
		  cout << ", and is the largest number entered so far";	
		cout << endl;
	
	}}




// Add a unit to each double entered
// 	enter values such as 10cm, 2.5In, 5ft, 3.33m
// 	Accept Four units:
// 		cm, m, in, ft
// 	 conversion factors:	1m == 100cm, 1in == 2.54cm, 1ft == 12in

void printConversions(double cm, double m, double in, double ft){
	cout << "The entered values: " << endl;
	cout << cm << " cm, " << endl;
	cout << m << " m," << endl;
	cout << in << " in," << endl;
	cout << ft << " ft " << endl;
}

void drill07(){
	vector<string> allowedUnits{"cm", "m", "in", "ft"};

	double  value;
	string unit;

	cout << "Enter A value following a unit of cm, m, in,ft : 24m or 24 m " << endl;

	double cm,m, in,ft;
	while(cin>>value>>unit){
			
		if(unit == "cm"){
			cm = value;
			m = cm/100;
			in=cm/2.54;
			ft=in/12;
			printConversions(cm, m, in, ft)	;
		}else if (unit =="m"){
			m = value;
			cm = m*100;
			in=cm/2.54;
			ft=in/12;
			printConversions(cm, m, in, ft)	;
		}else if (unit =="in"){
			in=value;
			cm =in*2.54;
			m = cm/100;
			ft=in/12;
			printConversions(cm, m, in, ft)	;
		}else if (unit =="ft"){
			ft=value;
			in=ft*12;
			cm =in*2.54;
			m = cm/100;
			printConversions(cm, m, in, ft)	;
		}else{
			//08
			//Reject illegal units like km yard etc.
		 cout << endl << "Illegal unit " << endl  	;
		}



	}
}

void drill08_09_10(){
	vector<double> meters{};

	double  value;
	string unit;

	cout << "Enter A value following a unit of cm, m, in,ft : 24m or 24 m " << endl;

	double cm,m, in,ft;
	while(cin>>value>>unit){
			
		if(unit == "cm"){
			cm = value;
			m = cm/100;
			in=cm/2.54;
			ft=in/12;
			printConversions(cm, m, in, ft)	;
			meters.push_back(m);
		}else if (unit =="m"){
			m = value;
			cm = m*100;
			in=cm/2.54;
			ft=in/12;
			printConversions(cm, m, in, ft)	;
			meters.push_back(m);
		}else if (unit =="in"){
			in=value;
			cm =in*2.54;
			m = cm/100;
			ft=in/12;
			printConversions(cm, m, in, ft)	;
			meters.push_back(m);
		}else if (unit =="ft"){
			ft=value;
			in=ft*12;
			cm =in*2.54;
			m = cm/100;
			printConversions(cm, m, in, ft)	;
			meters.push_back(m);
		}else{
			//08
			//Reject illegal units like km yard etc.
		 cout << endl << "Illegal unit " << endl  	;
		}

cout << endl << endl;		
	}
		double sum{0};
		for (double i: meters) sum+=i;
		sort(meters.begin(),meters.end(), doubleSort);
		cout << "Smallest: " << meters.at(0) << endl
		     << "Largest: " << meters.at(meters.size()-1) << endl
		     << "Sum of all entered values in meters " <<sum << endl; 

		cout << endl << endl;
		// 10 
		// Each value entered
		cout << "All entered values"  << endl;
	//	for (double i: meters) cout << i <<",";	
	//	cout << "\b";
		 std::ostringstream ss;
		 if(!meters.empty()) {
		    std::copy(meters.begin(), std::prev(meters.end()), std::ostream_iterator<int>(ss, ", "));
		    ss << meters.back();
		 }
		 std::cout << ss.str() << "\n";
		}

//		numbersEntered.push_back(i);
//		sort(numbersEntered.begin(),numbersEntered.end(), doubleSort);
//		smallest = numbersEntered.at(0);
//	        largest = numbersEntered.at(numbersEntered.size()-1);
//
//	       	cout << endl << "The smallest value is: " << smallest;
//		if(numbersEntered.size() ==1 || numbersEntered.at(1) > i)
//		  cout << ", and is the smallest number entered so far" ;	
//		cout << endl << "the largest value is " << largest;
//		if(numbersEntered.size() ==1 || (numbersEntered.at(numbersEntered.size()-2) < i))
//		  cout << ", and is the largest number entered so far";	
//		cout << endl;
//	




int main(){
//	drill01();
//	drill02();
//	drill03();
//	drill04();
//    	drill05();
//    	drill06();
//    	drill07();
    drill08_09_10();
}

