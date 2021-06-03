 #include <iostream>
using namespace std;
int main(){
	//convert yen to kroner
	constexpr double kr_to_yen =17.36;
	constexpr double d_to_p =0.72;	
	constexpr double d_to_ya =1.05;	
	
	double value = 1;
	char unit = ' ';

	cout << "Please enter value and then a unit of type y(en) <=>  k(roner), p(ounds) <=> d(ollar)" << endl;
	
	cin >> value >> unit;

	switch(unit){
		case 'y':
			cout << value << " yen equals to " << value/kr_to_yen << " dkk";
			break;
		case 'k':
			cout << value << " dkk iequals to "<< value*kr_to_yen << " yen" << endl;
			cout << value << " dkk iequals to "<< value*d_to_ya << " yaun";
			break;
		case 'p':
			cout << value << " pounds equals to "<< value/d_to_p << " dollars";
			break;
		case 'd':
			cout << value << " dollars equals to "<< value*d_to_p << " pounds";
			break;
		case 'c':
			cout << value << " yaun equals to "<< value/d_to_ya<< " kr";
			break;
		default:
			cout << "sorry that is not valid";
	}
}
