#include <iostream>
#include <string>
#include <fstream>
using namespace std;
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

class StringNode {
private:
	string data;
	StringNode* next;

public:
	//constructors
	StringNode(const string initData = string(), StringNode * initNext = nullptr);

	//mutators
	void setData(string newData);
	void setNext(StringNode* newNext);
	
	//accessors
	string getData() const;
	StringNode* getNext() const;
	bool contains(StringNode* head, string val);

	void printList(StringNode* front, ostream& out);
	void printNumber(StringNode* head);


};