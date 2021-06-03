#include <iostream>
using namespace std;
int main(){
	//convert yen to kroner
	const double kr_to_yen =17.36;
	const double d_to_p =0.72;	
	double value = 1;
	char unit = ' ';

	cout << "Please enter value and then a unit of type y(en) <=>  k(roner), p(ounds) <=> d(ollar)" << endl;
	
	cin >> value >> unit;

	if(unit =='y')
		cout << value << " yen equals to " << value/kr_to_yen << " dkk";
	else if(unit =='k')
		cout << value << " dkk iequals to "<< value*kr_to_yen << " yen";
	else if(unit =='p')
		cout << value << " pounds equals to "<< value/d_to_p << " dollars";
	else if(unit =='d')
		cout << value << " dollars equals to "<< value*d_to_p << " pounds";
	else
		cout << "sorry that is not valid";
}
