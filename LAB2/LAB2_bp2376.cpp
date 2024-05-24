//============================================================================
// Name         : lab2.cpp
// Author       : Bibek Poudel
// Version      : 1.0
// Date Created : 5/24/2024
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
    int elem;   // data element
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
    MyLinkedList();                         // empty list constructor
    ~MyLinkedList();                        // destructor to clean up all nodes
    bool empty() const;                     // is list empty?
    void addFront(int elem);                // add a new Node at the front of the list
    void removeFront();                     // remove front Node from the list
    void remove(int elem);                  // remove the first occurrence of an element of the list, if the element exists.
    unsigned int countElem(int elem) const; // count frequency of an element in the list
    int getIndexOf(int elem) const;         // returns first index of an element in the list, -1 if the element is not present
    void display() const;
    void readData(string);        // read a file and load it into the linked list
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
    while (!empty())
    {
        removeFront();
    } // to-do
}
//====================================
// Check if the list is empty or not
bool MyLinkedList::empty() const
{
    return head == NULL;
}
//====================================
// add a node at the front of list
void MyLinkedList::addFront(int elem)
{
    Node *v = new Node(elem); // to-do
    v->next = head;
    head = v;
}
//====================================
// remove the first node from the list
void MyLinkedList::removeFront()
{
    Node *old = head;
    head = old->next;
    delete old;
}
//=====================================
// remove the first occurrence of an element of the list, if the element exists
void MyLinkedList::remove(int elem)
{
    Node *current = head; // Start from the head of the list
    Node *previous = NULL;
    while (current != NULL && current->elem != elem)
    {
        previous = current;
        current = current->next;
    }
    if (current != NULL)
    {
        if (previous == NULL)
        {
            head = current->next;
        }
        else
        {
            previous->next = current->next;
        }
        delete current;
    }
}

//====================================
// count frequency of an element in the list
unsigned int MyLinkedList::countElem(int elem) const
{
    unsigned int count = 0; // Initialize count to 0
    Node *current = head;   // Start from the head of the list
    while (current != NULL)
    { // Iterate through the list
        if (current->elem == elem)
        {            // If the element matches
            count++; // Increment the count
        }
        current = current->next; // Move to the next node
    }
    return count; // Return the final count
}
//==============================================
// get first index of an element in the the list.
// returns -1 if the element is not present
int MyLinkedList::getIndexOf(int elem) const
{
    // Initialize a boolean to see if the index is found or not
    bool found = false;
    int index = 0;
    // Start from the head of the list
    Node *current = head;
    // Iterate through the list until the end or until the element is found
    while (current != NULL && found == false)
    {
        // If the current node contains the element, update the index
        if (current->elem == elem)
        {
            found = true;
        }
        // Move to the next node
        current = current->next;
        // If we have found the element, stop the loop
        if (current != NULL && current->elem != elem)
        {
            index++;
        }
    }
    if (found == false)
    {
        return -1;
    }
    // Return the index of the element
    return index;
}
//==============================================
// display all nodes of the linked list
void MyLinkedList::display() const
{
    // to-do
    Node *current = head; // Start from the head of the list
    cout << "Head ->";
    while (current != NULL)
    {
        cout << current->elem << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl; // Adding NULL to indicate the end of the list
}
//==============================================
// Load data from a file and add it to the Linked List
void MyLinkedList::readData(string path)
{
    ifstream file;
    file.open(path);
    if (file.is_open())
    {
        while (!file.eof())
        {
            int elem;
            file >> elem;
            addFront(elem);
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    file.close();
}
//=============================================
// Dump/write the contents of the list to a file
void MyLinkedList::writeData(string path) const
{
    ofstream file;
    file.open(path);
    if (file.is_open())
    {
        Node *current = head; // Start from the head of the list
        while (current != NULL)
        {
            file << current->elem << endl;
            current = current->next;
        }
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
    file.close();
}
//==================================================
