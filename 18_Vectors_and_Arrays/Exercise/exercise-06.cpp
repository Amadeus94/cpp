#include <string>
#include <iostream>

using namespace std;


//Exercise 06
//	Modify cat_dot() from prev exercise to take a string to be used as the seperator (rather than the dot) as its thirds argument	
string cat_dot(const string& s1, const string& s2, const string& separator){
	string result = s1; 
	result.append(separator);
	result.append(s2); // could also just manually append via for each loop via push_back()
	
	return result;
}

int main(){
	string s1 = "Niels";
	string s2 = "Bohr";
	string separator= "_";

	string result = cat_dot(s1,s2,separator);

	cout << result;

}


