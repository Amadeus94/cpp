#include  "..\..\..\Bjarnes_Standard_Header\std_lib_facilities.h"

// refactoring it:
	

	string getNameOfRecipient(){
		cout << "Enter then name of the person you want to write to \n >";
	string nameOfRecipient; 
	cin >> nameOfRecipient;

	nameOfRecipient[0] = toupper(nameOfRecipient[0]); 
	return nameOfRecipient;

	}	

	string getNameOfFriend(){
	cout << endl << "Enter the name of your friend" << endl ;
	string friend_name;
	cin>> friend_name;

	friend_name[0] = toupper(friend_name[0]); 
	return friend_name;	

	}	

	char getFriendsSex(){
		cout << endl; 
	char friend_sex = 0; // Didn't know you could initialize a char to 0 like this
	cout << "Enter the sex of your friend" << endl;
	while(friend_sex !='f' && friend_sex !='m'){

		cin >> friend_sex;
	}

	return friend_sex;
	}

	int getAgeOfRecipient(){

	cout << endl;
	cout << "Enter the age of the recipient" << endl;
	int age_recipient{};

	cin >> age_recipient;
	if(age_recipient<=0||  age_recipient >=110) {
		simple_error("You're kidding!");		
	}
	return age_recipient;
	}

	string enterYourName(){
	cout << "Enter your name" << endl;
	string name; 
	cin >> name;
	name[0] = toupper(name[0]);
	return name;
	}

int main(){

	string nameOfRecipient = getNameOfRecipient();
	string letter= "Dear " +  nameOfRecipient  + ",\n\n" + 
		"How are you? I am fine. I miss you.\n";
		
	string friend_name = getNameOfFriend();	
	letter+="Have you seen " +friend_name  + " lately ?\n"; 


	char friend_sex  = getFriendsSex();	
	if(friend_sex == 'm')
       		letter+="If you see " + friend_name +" please ask him to call me.";
	else
		letter+="If you see "  +friend_name  + " please ask her to call me.";

	int age_recipient= getAgeOfRecipient(); 

// should work with real includes instead of bjarnes	letter+=string("I hear you just had a birthday and you are ") +  age_recipient +   " Years old\n";

letter+=string("I hear you just had a birthday and you are ");
letter+=  age_recipient +   " Years old\n";
	if (age_recipient <12){
			letter+= "Next year you will be "  + age_recipient++;
	}else if(age_recipient==17){
		letter+="Next year you will be able to vote";
	} else if(age_recipient>70){
		letter+="I hope you will enjoy retirement ";
		
	
		}
	letter +="\n";

	string yourName = enterYourName();

	letter+="Your Sincerely, \n" + yourName; 
	cout << endl << endl << endl << endl << endl << letter;
		
}
