#include "StringNode.h"
/*
Morgan Knowles
11/6/16
Microsoft Visual Studio
Part 2   The Application
Joe and Sally still need help storing baby names.  This program is another attempt at storing and updating a list of baby names.
* Reads in baby names until the user indicates that there are no more. These strings should be stored in a linked list.
* Allows the user to choose between any of the following options, until he/she wishes to exit:
- print out all the names in the list
- add another name to the front of the list (user provides name)
- add a new name to the end of the list (this involves moving a pointer to the last
node and attaching a new node). The user provides the name.

- search for a particular name in the list (user enters name)
- output the number of names in the list
Part 3   File Output
Once the user has decided to exit, the last thing the main program should do before concluding is to store all the baby names in a file.  The program should prompt the user for the name of an output file, and output all baby names from the list into the file.  The names should be stored one per line.
*/


	//constructors
StringNode::StringNode(const string initData, StringNode * initNext) {//constructs new StringNode with data and next either provided by the user or set by default
	data = initData;
	next = initNext;
	}

	//mutators
void StringNode::setData(string newData) {//sets a StringNode's data
	data = newData;
	}

void StringNode::setNext(StringNode* newNext) {//sets a StringNode's next
	next = newNext;
	}

	//accessors
string StringNode::getData() const {//gets a StringNode's data
	return data;
	}

StringNode* StringNode::getNext() const {//gets a StringNode's next
	return next;
	}

bool StringNode::contains(StringNode* head, string val) {//check if list contains a value
	StringNode* ptr = head;
	while (ptr != nullptr) {//while pointer is not pointing to nothing
		if (ptr->getData() == val) {
			return true;
		}
		ptr = ptr->getNext();//increments through node list
	}
	return false;
}

void StringNode::printList(StringNode* front, ostream& out) {//prints a list to file or screen
	StringNode* ptr = front; //ptr is initialized to the to the first node
	while (ptr != nullptr) {//while pointer is not pointing to nothing
		out << ptr->getData() << endl;//print or do whatever(this while loop can be used for different things)
		ptr = ptr->getNext();//increments through node list. Everytime this loop executes, ptr is set to the next space.
	}
}

void StringNode::printNumber(StringNode* head) {//prints the number of names currently in the list
	StringNode* ptr = head;//sets new StringNode ptr to the front of the list(head)
	int num = 0;//counter
	while (ptr != nullptr) {//while pointer is not pointing to nothing
		num++;//add one to num
		ptr = ptr->getNext();//increments through node list
	}
	cout << "There are " << num << " names in the list." << endl;
}


