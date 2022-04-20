#include <string>
#include <iostream>

using namespace std;


//Exercise 05
//	Write a  function string cat_dot(const string& s1, const string& s2)
//		that concatenates two string s with a dot in between
//			cat_dot("Niels", "Bohr") returns "Niels.Bohr"
string cat_dot(const string& s1, const string& s2){
	string result = s1; 
	result.push_back('.');
	result.append(s2); // could also just manually append via for each loop
	
	return result;
}

int main(){
	string s1 = "Niels";
	string s2 = "Bohr";

	string result = cat_dot(s1,s2);

	cout << result;

}


