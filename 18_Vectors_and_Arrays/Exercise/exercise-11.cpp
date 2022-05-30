#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include<iostream>

#define MAX_LEVEL 6
const float p = 0.5;


using namespace std;

/*
 * ==============================	skip list	==========================
 * 
 * 	A skip list ia singly linked list with additional, coarser, linked lists
 * 		these additional lists allow 
 * 			RAPID LOCATION,
 * 			INSERTION AND REMOVAL OF NODES
 * 		Values in a skip list are maintained in order at all times
 *
 * 		Basically you have a normal list that is ordered
 * 			And then you have another list that takes like each 5th element or so and then you can skip  if is > than that item
 *
 * 			1 -> 2  ->  3 ->  6 ->  9   -> 			normal list
 * 			
 * 			1 -> 		3 		->  9				highlane list
 *
 *
 *		So in other words - if you search for "6" it will look at highlane tree and go to 1 then 3 then check if lower than next highline element .. if it is ... 
 *			then start traverse normally on normal list from there three it will traverse the "highlane"  list  to skip the  list
 *
 */

// Copy paste linked list  implementation
// 		Make adjustments
// 		resources
// 			https://skiplist.readthedocs.io/en/latest/design.html#:~:text=C%2B%2B%20Skip%20List-,Design%20of%20the%20C%2B%2B%20Skip%20List,in%20order%20at%20all%20times.
// 			https://www.geeksforgeeks.org/skip-list-set-2-insertion/
//

// Implementing it from declarations only  from this link
// 	https://www.sanfoundry.com/cpp-program-implement-skip-list/
//

struct Node
{
	int value;
	Node **successor;

	Node(int level, int &value){
		successor = new Node * [level + 1];
		//memset(successor,0,sizeof(Node*) * (level + 1)); // change to new?
		//		???
		this->value = value;
		
	};
	~Node();
};

struct SkipList
{
	Node *header;
	int value;
	int level;

	SkipList()
	{
		header = new Node(MAX_LEVEL, value);
		level = 0;
	}

	~SkipList()
	{
		delete header;
	}

	void display();
	bool contains(int &);
	void insert_element(int &);
	void delete_element(int &);
};



bool SkipList::contains(int& value){

	return true;
}
