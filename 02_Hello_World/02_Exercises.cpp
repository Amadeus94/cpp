#include <iostream>
using namespace std;

// Turn right in the corridor
void stepForward(int i){
	cout << "Robot steps " << i << " steps forward" << endl;
}

void turnRight(){
	cout << "Robot turns right" << endl;
}

void openDoor(){

	cout << "Robot opens door" << endl;
}

void closeDoor(){
	cout << "Robot closes door" << endl;
}

void turnAround(){
	cout << "Robot turns around" << endl;

}
void HOME(){
	cout << "Home ...Alas";
}
int main(){
	// assuming the robot is 10 feet away to turn right in the corridor
	cout << "Assuming the robot is 10 feet away to turn right in the corridor and then wants to open a door and close it these are some of the steps: "  << endl;

	stepForward(10);
	turnRight();
	stepForward(5);
	openDoor();
	stepForward(1);
	turnAround();
	closeDoor();
	turnAround();
	stepForward(3); 
	HOME();
	return 0;
}

