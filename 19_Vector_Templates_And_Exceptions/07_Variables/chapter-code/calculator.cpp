#include <iostream>
#include <error.h>
#include <string>
#include <vector>
using namespace std;

class Variable{
public:
	string name;
	double value;
};

vector<Variable> var_table;

double get_value(string s)
	//return the value of the Variable named s
{
	for(const Variable& v : var_table)
		if(v.name==s) 
			return v.value;
	cout << "error: get: undefined variable:\t " << s; 
	throw error;
}

void set_value(string s, double d)
	// set the variable named s to d
{
	for(Variable& v : var_table)
		if(v.name == s){
			v.value = d;
			return;
	}
	throw error;//"set: undefined variable"
}



