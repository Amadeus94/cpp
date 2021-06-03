#include <iostream>


int squar(int num){
	auto s = num;
	for(int i = 1; i<num; ++i){
		s+=num;
}
	
	return s;
}
int main (){

	std::cout << squar(3);
}
