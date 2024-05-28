/**
 * @file:Assignment_1_bp2376.cpp
 * @author:Bibek Poudel
 * @description Doubly LinkedList implementation in C++
 * @date 2024-05-26
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
DoublyLinkedList::DoublyLinkedList()
{
	head = new Node(); // create head sentinel node
	tail = new Node(); // create tail sentinel node
	head->next = tail; // head points to tail
	tail->prev = head; // tail points to head
}
//============================================================
DoublyLinkedList::~DoublyLinkedList()
{
	while (!isEmpty())
	{
		removeFront();
	}
	delete head; // delete head sentinel node
	delete tail; // delete tail sentinel node
}
//============================================================
bool DoublyLinkedList::isEmpty() const
{
	return head->next == tail; // list is empty if head points to tail
}
//============================================================
const string &DoublyLinkedList::front() const
{
	if (isEmpty())
	{
		throw runtime_error("List is empty");
	}
	return head->next->elem; // return the element after the head sentinel node
}
//============================================================
const string &DoublyLinkedList::back() const
{
	if (isEmpty())
	{
		throw runtime_error("List is empty");
	}
	return tail->prev->elem; // return the element before the tail sentinel node
}
//============================================================
void DoublyLinkedList::addFront(const string &elem)
{
	Node *newNode = new Node(elem);
	newNode->next = head->next;
	newNode->prev = head;
	head->next->prev = newNode;
	head->next = newNode;
}
//============================================================
void DoublyLinkedList::addBack(const string &elem)
{
	Node *newNode = new Node(elem);
	newNode->next = tail;
	newNode->prev = tail->prev;
	tail->prev->next = newNode;
	tail->prev = newNode;
}
//============================================================
void DoublyLinkedList::removeFront()
{
	if (isEmpty())
	{
		throw runtime_error("List is empty");
	}
	Node *temp = head->next;
	head->next = temp->next;
	temp->next->prev = head;
	delete temp;
}
//============================================================

void DoublyLinkedList::removeBack()
{
	if (isEmpty())
	{
		throw runtime_error("List is empty");
	}
	Node *temp = tail->prev;
	tail->prev = temp->prev;
	temp->prev->next = tail;
	delete temp;
}

//============================================================

void DoublyLinkedList::reverseList()
{
	if (head == NULL)
	{
		throw runtime_error("List is empty");
	}
	Node *curr = head;
	while (curr != NULL)
	{
		Node *temp = curr->next;
		curr->next = curr->prev;
		curr->prev = temp;
		curr = curr->prev;
	}
	Node *temp = head;
	head = tail;
	tail = temp;
}
//============================================================
bool DoublyLinkedList::isPalindrome() const
{
	if (head == nullptr)
	{
		// Empty list is considered a palindrome
		return true;
	}

	Node *curr = head;
	Node *temp = tail;

	while (curr != nullptr && temp != nullptr)
	{
		// Compare elements from the beginning and end
		if (curr->elem != temp->elem)
		{
			// If elements don't match, it's not a palindrome
			return false;
		}

		// Move towards the middle
		curr = curr->next;
		temp = temp->prev;
	}

	// If the loop completes without finding any mismatches, it's a palindrome
	return true;
}
