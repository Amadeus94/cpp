#include <iostream>
using namespace std;

int main() {
	// the char 'b' equal char('a' + 1)

	int i=0;
	int end='z'-'a';
	while(i<=end){
		cout << char('a'+i) << "\t" << int('a'+i) << endl; 
		i++;
	}

	// for statement
	int endu='Z'-'A';
	for(int j {endu};j>=0; j--){ 
		cout << char('A'+j) << "\t" << int('A'+j) << endl; 
	}
}

