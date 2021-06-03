#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	
	vector<string> bleepWords {"fuck", "hell", "mogga", "reyv", "fani","bøssi","doyggj","reyvarhol","helveti"}; 
		
	//string dislikedWord ="fuck";
	
	for(string key;cin>>key;){
		if (find(bleepWords.begin(),bleepWords.end(), key) !=bleepWords.end())
		     cout << "bleep" << endl;
		else
		     cout << key << endl;
	}
}
