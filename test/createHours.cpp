#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){

    int d=1100;
    vector<int> hour;

    for (int i= 0; i<562; i++){
        if(i%60==0){
            d+=100;
        }
        hour.push_back(i%60+d);
    }

    for(int i: hour){
        cout << i << endl;
    }


    ofstream myFile;
    myFile.open("hours.txt"); 
    for(int i: hour){
        myFile << i << endl;
    }

    myFile.close();

    return 0;
}
