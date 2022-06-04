#include <iostream>
using namespace std;
/*		Try This  01
 *		
 *		Write a function 
 *			void copy(int* f1, int* e1, int* f2)
 *		that copies the lements of an array of ints defined by [f1:e1] into another [f2:f2+(e1-f1)).
 *		Use only the iterator operations mentioned above (Not subscripting)
 * 
 */	



void copy(int* f1, int* e1, int* f2){
	while(f1!=e1){
		*f2=*f1;
		f1++;
		f2++;
	}
}

int main(){
	int array[] = { 1, 2, 3 };
	int newArray[3];


	copy(array, array+3, newArray) ;
//					  ^One past


	for(int i=0; i<3; i++){
		cout << *(newArray+i);
	}



}
