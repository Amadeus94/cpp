#include <iostream>
using namespace std;


void printRepeatedWords(){
	
		string previous =" ";
	string current;
	while(cin>>current){
		if(previous ==current)
			cout << "repeated word: " << current << "\n";
		previous = current;	
	}
	cout << endl << "end of file: ctrl+z + enter in windows "<< endl << "ctrl+d in unix";
}

void printWhereRepeatedWords(){

	int number_of_words =0;
	string previous =" ";
	string current;
	while(cin>>current){
		number_of_words++;
		if(previous ==current)
			cout <<"word number :  " << number_of_words << endl <<" repeated word: " << current << "\n";
		previous = current;	
	}
	cout << endl << "end of file: ctrl+z + enter in windows "<< endl << "ctrl+d in unix";
}


int main(){
printWhereRepeatedWords(); 
int k$ = 3;
return 0;
}
