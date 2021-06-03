#include <iostream>
#include <bitset>

using namespace std;
int main(){
	// conclusion: It is assigned randomly ... i = 0 ; j = 16 in this case 
	//  ie. undefined
	int i;
	int j;
	cout << j ;
	cout << i+j << endl;


	// safe conversions
	bool o = true;
	int i1 = o;
	int i2 = 'x';
	cout << o << " " << i1 << " " << i2; 

	// unsafe conversion 
	// 	Narrowing .. 20000 int into a char
	
	int k = 313121;
	bitset<8> x(k); // equals 00010001
	char p = k;	// 	ie. 33  ... ie char p = 33;
	char dj {k}; // should give error - doesnt allow narrowing conversions
	char dj {k}; // should give error - doesnt allow narrowing conversions
	cout << endl << p << ";  in bits: " << x;


	// testing different inputs
	double d = 0;
	while(cin >> d ){
		int i = d;
		char c = i;
		int i2 = c;
		cout << endl << endl <<  "d== " << d << endl
			<<  "i==" << i2 << endl 
			<< " char(" << c << ")\n";
	}

}
