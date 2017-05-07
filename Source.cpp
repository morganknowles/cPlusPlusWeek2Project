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
int main() {
	char userOption;
	string babyName;//accepts baby names from user
	string search;//used for searching for a specific name in the list
	string userFile;//file name for end of program storage
	StringNode* first;//used to put a name at the front of the list
	StringNode* head = nullptr;//empty list
	StringNode* list;//baby names stored here

	cout << "Enter two names to begin: " << endl;
	cin >> babyName;
	head = new StringNode(babyName, nullptr);//stores first name at the front of list
	cin >> babyName;
	head->setNext(new StringNode(babyName,nullptr));//stores second name at the next list position
	list = head->getNext();//initialize list with the next place in head
	

	cout << "___________________________________" << endl;
	cout << "Menu:" << endl;
	cout << "Print all names (p)" << endl;
	cout << "Print the number of names in the list (n)" << endl;
	cout << "Add a name to the front of list (f)" << endl;
	cout << "Add a name to the end of list (e)" << endl;
	cout << "Search for a name (s)" << endl;
	cout << "Display the menu (m)" << endl;
	cout << "Quit (q)" << endl;
	cout << "___________________________________" << endl;

	do {
		cin >> userOption;
		switch (userOption) {
	
		case 'p':
			list->printList(head,cout);
			break;

		case 'n':
			list->printNumber(head);
			break;

		case 'f':
			cout << "Enter name: ";
			cin >> babyName;//collect new data
			first = new StringNode(babyName);//initialized first node with user's value
			first->setNext(head);//set first's next to head
			head = first;	
			cout << endl << babyName << " was added to the front of the list. " << endl;
			break;

		case 'e': 
			cout << "Enter name: ";
			cin >> babyName;
			list->setNext(new StringNode(babyName));//sets next node to new StringNode
			list = list->getNext();//list's next node
			cout << endl << babyName << " was added to the end of the list. " << endl;
			break;	
		case 's':
			cout << "Enter name to search for: ";
			cin >> search;
			if (list->contains(head, search)) {//if search is in list
				cout << search << " is in this list." << endl;
			}
			else {//if search is not in list
				cout << search << " is not in this list." << endl;
			}
			break;
		case 'm':
			cout << "___________________________________" << endl;
			cout << "Menu:" << endl;
			cout << "Print all names (p)" << endl;
			cout << "Print the number of names in the list (n)" << endl;
			cout << "Add name to front of list (f)" << endl;
			cout << "Add name to end of list (e)" << endl;
			cout << "Search for a name (s)" << endl;
			cout << "Quit (q)" << endl;
			cout << "___________________________________" << endl;
			break;
	
		default:
			break;
		}
	} while (userOption != 'q');

	cout << "Enter a filename (ex: file.txt) " << endl;
	cin >> userFile;
	ofstream outputFile;
	outputFile.open(userFile);
	list->printList(head, outputFile);
	outputFile.close();


}
