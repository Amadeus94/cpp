#include <fstream>
#include <iostream>

using namespace std;
/*
 * Ex12 - Create a File_handle class with a 
 * 		  constructor
 * 				that takes a string argument ( the file name)
 * 		   		and opens the file in the constructor
 *		  Destructor
 *		  	closes it in the destructor 
 */
class File_handle{
public:
	string filename;
	ifstream ifs;
	File_handle(string fn) {
		filename=fn;
		//ifs=ifs(filename);
		ifs.open(fn, ios::out);
		if(!ifs)
			cout << "error";
		else
			cout << filename << " opened succesfully!" << endl;

	}	

	~File_handle(){
		ifs.close();
		cout << endl << "file closed successfully" << endl;
	}
};

int main(){
	File_handle ifs("test.txt");

	cout << ifs.filename;
}
