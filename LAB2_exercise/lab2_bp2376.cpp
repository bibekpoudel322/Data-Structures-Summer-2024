//============================================================================
// Name         : lab2.cpp
// Author       : Bibek Poudel
// Version      : 1.0
// Date Created : 5/26/2024
// Date Modified:
// Description  : Singly Linked-List implementation in C++
//============================================================================
// starter_code_begins
#include <iostream>
#include <string>
#include <fstream>
#include <exception>
#include <sstream>
using namespace std;
//====================================
class Node
{
private:
	int elem;	// data element
	Node *next; // Link (pointer) to the next Node

public:
	Node(int elem) : elem(elem), next(NULL)
	{
	}
	friend class MyLinkedList;
};
//=====================================
class MyLinkedList
{
private:
	Node *head; // pointer to the head of list
public:
	MyLinkedList();							// empty list constructor
	~MyLinkedList();						// destructor to clean up all nodes
	bool empty() const;						// is list empty?
	void addFront(int elem);				// add a new Node at the front of the list
	void removeFront();						// remove front Node from the list
	void remove(int elem);					// remove the first occurrence of an element of the list, if the element exists.
	unsigned int countElem(int elem) const; // count frequency of an element in the list
	int getIndexOf(int elem) const;			// returns first index of an element in the list, -1 if the element is not present
	void display() const;
	void readData(string);		  // read a file and load it into the linked list
	void writeData(string) const; // write the linked list to a file
};
//=====================================
void listCommands()
{
	cout << "List of available Commands:" << endl
		 << "display            : Display the Linked List" << endl
		 << "addFront <element> : Add <element> to the front of the Linked List" << endl
		 << "removeFront        : Remove the front node of the Linked List" << endl
		 << "remove        	  : Remove the first occurrence of an element of the list (if exists)" << endl
		 << "count <element>    : count frequency of an element in the list" << endl
		 << "indexOf <element>  : return first index of an element in the list (-1 of not present)" << endl
		 << "read <file_name>   : Load the data from <file> and add it into the Linked List" << endl
		 << "write <file_name>   : Dump the contents of the Linked list to <file>" << endl
		 << "help               : Display the list of available commands" << endl
		 << "exit               : Exit the Program" << endl;
}
//=======================================
// main function
int main()
{
	MyLinkedList myList;

	listCommands();
	string user_input;
	string command;
	string parameter;

	do
	{
		cout << ">";
		getline(cin, user_input);

		// parse user input into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr, command, ' ');
		getline(sstr, parameter);

		if (command == "display")
			myList.display();
		else if (command == "addFront" or command == "af")
			myList.addFront(stoi(parameter)), myList.display();
		else if (command == "removeFront" or command == "rf")
			myList.removeFront(), myList.display();
		else if (command == "remove" or command == "r")
			myList.remove(stoi(parameter)), myList.display();
		else if (command == "count")
			cout << parameter << " occurs " << myList.countElem(stoi(parameter)) << " time(s) in the list" << endl;
		else if (command == "indexOf")
			cout << "First index of " << parameter << " in the list is: " << myList.getIndexOf(stoi(parameter)) << endl;
		else if (command == "read")
			myList.readData(parameter), myList.display();
		else if (command == "write")
			myList.writeData(parameter);
		else if (command == "help")
			listCommands();
		else if (command == "exit")
			break;
		else
			cout << "Invalid Commad !!" << endl;
	} while (command != "exit");

	return EXIT_SUCCESS;
}
//====================================
// constructor
MyLinkedList::MyLinkedList()
{
	this->head = NULL;
}
// starter_code_ends
//====================================
//  destructor to clean up all nodes
MyLinkedList::~MyLinkedList()
{
	while (!empty()) // while the header doesn't point to the null pointer
	{
		removeFront(); // keep deleting the nodes
	} // to-do
}
//====================================
// Check if the list is empty or not
bool MyLinkedList::empty() const
{
	return head == NULL; // return true if the head is pointing to null pointer (i.e the list is empty)
}
//====================================
// add a node at the front of list
void MyLinkedList::addFront(int elem)
{
	Node *v = new Node(elem); // create a new node and store the element to the node
	v->next = head;			  // link the node before the first node
	head = v;				  // update the header to point to the new joined node
}
//====================================
// remove the first node from the list
void MyLinkedList::removeFront()
{
	if (head == NULL) // if the node list is empty print a message
	{
		cout << "The List is empty" << endl;
	}
	else
	{
		Node *old = head;  // store the address of the node to be removed
		head = head->next; // Update the head to point to the next node
		// Delete the old head node
		delete old;
	}
}
//=====================================
// remove the first occurrence of an element of the list, if the element exists
void MyLinkedList::remove(int elem)
{
	bool found = false;		  // flag variable for found
	Node *traversal = head;	  // Pointer to a node for traversal around list
	Node *previous = nullptr; // Pointer to the previous node

	if (elem == head->elem) // check if we found the element in the first node
	{
		removeFront(); // remove the node
		found = true;
		cout << "First occurrence of " << elem << " has been successfully deleted from the list." << endl;
	}
	else
	{
		while (traversal != nullptr && !found) // loop until the element is found
		{
			if (traversal->elem == elem)
			{
				found = true; // set found flag to true
			}
			else
			{
				previous = traversal;		 // update the previous node with the traversal
				traversal = traversal->next; // move to next node
			}
		}

		if (found) // if we found the element
		{
			if (traversal->next == nullptr) // if the next node is null then we dont need to connect previous node
			{
				previous->next = nullptr;
			}
			else
			{
				previous->next = traversal->next; // else if it is in the middle, link to next node
			}
			delete traversal; // delete the node
			cout << "First occurrence of " << elem << " has been successfully deleted from the list." << endl;
		}
		else
		{
			cout << "No such element found" << endl; // if the element to be deleted is not found, print an error message
		}
	}
}

//====================================
// count frequency of an element in the list
unsigned int MyLinkedList::countElem(int elem) const
{
	int count = 0; // set counter to zero
	Node *traversal = head;
	while (traversal != NULL) // traverse through the list
	{
		if (traversal->elem == elem)
		{
			count++; // update the counter when the element is detected
		}
		traversal = traversal->next; // go to next node
	}
	return count;
}
//==============================================
// get first index of an element in the the list.
// returns -1 if the element is not present
int MyLinkedList::getIndexOf(int elem) const
{
	int index = 0;			  // initialize the index to zero
	bool found = false;		  // set boolean for found
	Node *traversal = head;	  // create a pointer to traverse around the list
	while (traversal != NULL) // traverse around the list
	{
		if (traversal->elem == elem) // if element is found
		{
			found = true; // set boolean found to true
			return index; // return the index of first occurrence of element
		}
		index++;					 // increase the index
		traversal = traversal->next; // traverse to next node
	}
	if (found == false) // if not found
	{
		return -1; // return -1
	}
}
//==============================================
// display all nodes of the linked list
void MyLinkedList::display() const
{
	cout << "Head->"; // traverse around the list and display element
	Node *traversal = head;
	while (traversal != NULL)
	{
		cout << traversal->elem << "->";
		traversal = traversal->next;
	}
	cout << "NULL" << endl;
}
//==============================================
// Load data from a file and add it to the Linked List
void MyLinkedList::readData(string path)
{
	ifstream myfile(path); // define an ifstream object
	if (!myfile.is_open()) // check if file is open
	{
		throw runtime_error("Error: Unable to open file for reading.");
	}
	int data;			   // integer data variable
	while (myfile >> data) // until we are reading data from file
	{
		addFront(data); // add the data to the list
	}
	myfile.close(); // close the file
}
//=============================================
// Dump/write the contents of the list to a file
void MyLinkedList::writeData(string path) const
{
	int counter = 0;
	ofstream myfile(path); // define a ofstream file object
	if (!myfile.is_open()) // check the file is open or not
	{
		throw runtime_error("Error: Unable to open file for writing.");
	}
	Node *traversal = head; // traverse around the list
	while (traversal != NULL)
	{
		myfile << traversal->elem << endl; // write the content of the list to the file
		counter++;
		traversal = traversal->next;
	}
	cout << counter << " records have been exported to " << path << endl;
	myfile.close(); // close the file
}
//==================================================
