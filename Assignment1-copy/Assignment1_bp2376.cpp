/**
 * @file:Assignment1_bp2376.cpp
 * @author:Bibek Poudel
 * @description Doubly LinkedList implementation in C++
 * @date 5/29/2024
 */
// startercode_begins
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Node
{
private:
	string elem; // data element (type string in this case)
	Node *next;	 // Link (pointer) to the next Node
	Node *prev;	 // Link (pointer) to the previous Node
	friend class DoublyLinkedList;

public:
	Node() : next(NULL), prev(NULL)
	{
	}
	Node(string elem) : elem(elem), next(NULL), prev(NULL)
	{
	}
};
//==============================================================
class DoublyLinkedList
{
private:
	Node *head; // pointer to the head of List
	Node *tail; // pointer to the tail of List
public:
	DoublyLinkedList();				   // constructor to create dummy head and tail nodes
	~DoublyLinkedList();			   // destructor to clean up all nodes
	bool isEmpty() const;			   // return true if the list is empty
	const string &front() const;	   // returns the const reference of the element from the first valid Node of list, throw an exception if the list is empty
	const string &back() const;		   // returns the const reference of the element from last valid Node of the list, throw an exception if the list is empty
	void addFront(const string &elem); // add a new node to the front of list (after head)
	void addBack(const string &elem);  // add a new node to the back of the list (before tail)
	void removeFront();				   // remove front node from list, throw an exception if the list is empty
	void removeBack();				   // remove last node from list, throw an exception if the list is empty
	void reverseList();				   // reverse the list
	bool isPalindrome() const;		   // return true if the list is Palindrome, false otherwise
	void display() const;			   // display all element of the list
};
//===================================
void listCommands()
{
	cout << "List of available Commands:" << endl
		 << "display            : Display the Doubly Linked List" << endl
		 << "front              : Display the first element of the List" << endl
		 << "back               : Display the last element of the List" << endl
		 << "addFront <elem>    : Add a new Node at the beginning of the List" << endl
		 << "addBack  <elem>    : Add a new Node at the end of the List" << endl
		 << "removeFront        : Remove the first Node of the Linked List" << endl
		 << "removeBack         : Remove the last Node of the Linked List" << endl
		 << "isEmpty            : Check if the List is empty?" << endl
		 << "reverse            : Reverse the Linked List" << endl
		 << "isPalindrome       : Check if the List is Palindrome or not?" << endl
		 << "help               : Display the list of available commands" << endl
		 << "exit               : Exit the Program" << endl;
}
//===================================
int main()
{
	DoublyLinkedList myList;
	listCommands();
	string user_input;
	string command;
	string parameter;

	do
	{
		cout << ">";
		getline(cin, user_input);

		// parse user-input into command and parameter(s)
		stringstream sstr(user_input);
		getline(sstr, command, ' ');
		getline(sstr, parameter);

		try
		{
			if (command == "display" or command == "d")
				myList.display();
			else if (command == "front" or command == "f")
				cout << "Front = " << myList.front() << endl;
			else if (command == "back" or command == "b")
				cout << "Back = " << myList.back() << endl;
			else if (command == "addFront" or command == "af")
				myList.addFront(parameter), myList.display();
			else if (command == "addBack" or command == "ab")
				myList.addBack(parameter), myList.display();
			else if (command == "removeFront" or command == "rf")
				myList.removeFront(), myList.display();
			else if (command == "removeBack" or command == "rb")
				myList.removeBack(), myList.display();
			else if (command == "isEmpty" or command == "ise")
				cout << "List is " << (myList.isEmpty() ? "Empty" : "Not Empty") << endl;
			else if (command == "reverse" or command == "r")
				myList.reverseList(), myList.display();
			else if (command == "isPalindrome" or command == "isp")
				cout << "List is " << (myList.isPalindrome() ? "Palindrome" : "Not Palindrome") << endl;
			else if (command == "help" or command == "h")
				listCommands();
			else if (command == "exit" or command == "e")
				break;
			else
				cout << "Invalid Commad !!" << endl;
		}
		catch (exception &e)
		{
			cout << "Exception: " << e.what() << endl;
		}

	} while (command != "exit" and command != "quit");

	return EXIT_SUCCESS;
}
//============================================================
#ifdef _WIN32
void DoublyLinkedList::display() const
{
	Node *curr = head;
	while (curr != NULL)
	{
		cout << "+------";
		curr = curr->next;
	}
	cout << "+" << endl
		 << "|";
	curr = head;
	while (curr != NULL)
	{
		if (curr == head)
			cout << " Head |";
		else if (curr == tail)
			cout << " Tail |";
		else
			cout << setw(5) << curr->elem << " |";

		curr = curr->next;
	}
	curr = head;
	cout << endl;
	while (curr != NULL)
	{
		cout << "+------";
		curr = curr->next;
	}
	cout << "+" << endl;
}
//====================================================================
#else
void DoublyLinkedList::display() const
{
	Node *curr = head;
	while (curr != NULL)
	{
		cout << "╔══════╗    ";
		curr = curr->next;
	}
	cout << endl
		 << "║";
	curr = head;
	while (curr != NULL)
	{
		if (curr == head)
			cout << " Head ║<══>║";
		else if (curr == tail)
			cout << " Tail ║";
		else
			cout << setw(6) << curr->elem << "║<══>║";

		curr = curr->next;
	}
	curr = head;
	cout << endl;
	while (curr != NULL)
	{
		cout << "╚══════╝    ";
		curr = curr->next;
	}
	cout << endl;
}
#endif
// startercode_ends
//===========================================================
// Constructor to create Sentinel (dummy) nodes
DoublyLinkedList::DoublyLinkedList() // Constructor to create Sentinel (dummy) nodes
{
	head = new Node(); // Constructor to create head (dummy) nodes
	tail = new Node(); // Constructor to create tail (dummy) nodes
	head->next = tail; // assign tail to head->next
	tail->prev = head; // assign head to tail->prev
}
//============================================================
DoublyLinkedList::~DoublyLinkedList() // Destructor to clean up all nodes
{
	while (!isEmpty()) // while list is not empty
	{
		removeFront(); // remove front node
	}
	delete head; // delete head;
	delete tail; // delete tail;
}
//============================================================
bool DoublyLinkedList::isEmpty() const // return true if the list is empty
{
	return head->next == tail; // if head->next points to tail, then list is empty
}
//============================================================
const string &DoublyLinkedList::front() const
{
	if (isEmpty()) // if list is empty
	{
		throw runtime_error("List is Empty"); // throw an exception
	}
	else
	{
		return head->next->elem; // return the element of the first valid node
	}
}
//============================================================
const string &DoublyLinkedList::back() const // returns the const reference of the element from last valid Node of the list
{
	if (isEmpty()) // if list is empty
	{
		throw runtime_error("List is Empty"); // throw an exception
	}
	else
	{
		return tail->prev->elem; // return the element of the last valid node
	}
}
//============================================================
void DoublyLinkedList::addFront(const string &elem) // add a new node to the front of list (after head)
{
	Node *v = new Node(elem); // create a new node
	v->prev = head;			  // assign head to v->prev
	v->next = head->next;	  // assign head->next to v->next
	head->next->prev = v;	  // assign v to head->next->prev
	head->next = v;			  // assign v to head->next
}
//============================================================
void DoublyLinkedList::addBack(const string &elem) // add a new node to the back of the list (before tail)
{
	Node *v = new Node(elem); // create a new node
	v->next = tail;			  // assign tail to v->next
	v->prev = tail->prev;	  // assign tail->prev to v->prev
	tail->prev->next = v;	  // assign v to tail->prev->next
	tail->prev = v;			  // assign v to tail->prev
}
//============================================================
void DoublyLinkedList::removeFront()
{
	if (isEmpty()) // check if the list is empty
	{
		throw runtime_error("List is Empty"); // throw an exception
	}
	else
	{
		Node *old = head->next;		 // store the first valid node in old
		head->next = old->next;		 // assign old->next to head->next
		old->next->prev = old->prev; // assign old->prev to old->next->prev
		delete old;					 // delete old
	}
}
//============================================================
void DoublyLinkedList::removeBack() // remove last node from list, throw an exception if the list is empty
{
	if (isEmpty())
	{
		throw runtime_error("List is Empty"); // throw an exception
	}
	else
	{
		Node *old = tail->prev;		 // store the last valid node in old
		tail->prev = old->prev;		 // assign old->prev to tail->prev
		old->prev->next = old->next; // assign old->next to old->prev->next
	}
}
//============================================================
void DoublyLinkedList::reverseList()
{
	if (isEmpty())
	{
		throw runtime_error("List is Empty"); // throw an exception
	}
	else
	{
		Node *current = head->next; // store the first valid node in current
		Node *temp = nullptr;		// create a temporary node
		while (current != tail)		// while current is not tail
		{
			// Swap prev and next pointers of the current node
			temp = current->prev;		   // store current->prev in temp
			current->prev = current->next; // assign current->next to current->prev
			current->next = temp;		   // assign temp to current->next
			current = current->prev;	   // assign current->prev to current
		}
		// Now, current is null, and temp points to the last node (before head)
		temp = head->next;		 // store head->next in temp
		head->next = tail->prev; // assign tail->prev to head->next
		tail->prev = temp;		 // assign temp to tail->prev

		// Update the next and prev pointers of the first and last nodes
		head->next->prev = head; // assign head to head->next->prev
		tail->prev->next = tail; // assign tail to tail->prev->next
	}
}

//============================================================
bool DoublyLinkedList::isPalindrome() const
{
	if (isEmpty())
	{
		throw runtime_error("List is Empty"); // throw an exception
	}
	else
	{
		Node *traversalfront = head->next;												 // store head->next in traversalfront
		Node *traversalback = tail->prev;												 // store tail->prev in traversalback
		while (traversalfront != traversalback && traversalfront->prev != traversalback) // check if traversalfront is not equal to traversalback and traversalfront->prev is not equal to traversalback
		{
			if (traversalfront->elem != traversalback->elem) // check if traversalfront->elem is not equal to traversalback->elem
			{
				return false; // return false
			}
			traversalfront = traversalfront->next; // assign traversalfront->next to traversalfront
			traversalback = traversalback->prev;   // assign traversalback->prev to traversalback
		}
		return true; // return true
	}
}
