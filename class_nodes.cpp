#include <iostream>
#include <string>

using namespace std;

class Author
{
    enum
    {
        MAXSIZE = 25
    };

private:
    string name;
    int age, nbooks;
    string titles[MAXSIZE];

public:
    Author() : name(""), age(0), nbooks(0)
    {
        for (int i = 0; i < MAXSIZE; ++i)
        {
            titles[i] = "";
        }
    }

    Author(string name, int age, int nbooks, string titles[]) : name(name), age(age), nbooks(nbooks)
    {
        for (int i = 0; i < nbooks; ++i)
        {
            this->titles[i] = titles[i];
        }
    }

    void display()
    {
        cout << "Author: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Number of authored books: " << nbooks << endl;
    }

    friend class DLinkedList; // allow DLinkedList access
};

typedef Author Elem; // list element type

class DNode
{ // doubly linked list node
private:
    Elem elem;          // node element value
    DNode *next, *prev; // next and previous nodes in list
public:
    DNode() {}
    DNode(const Elem &e) : elem(e), prev(NULL), next(NULL) {}
    friend class DLinkedList; // allow DLinkedList access
};

// Declaration of the DLinkedList class
class DLinkedList
{ // doubly linked list
public:
    DLinkedList(); // constructor
    void displayAll();
    void insert(const Elem &e);

private:
    DNode *header, *trailer; // list sentinels
};

// Definition of the constructor of DLinkedList
DLinkedList::DLinkedList()
{
    header = new DNode; // create sentinels
    trailer = new DNode;
    header->next = trailer; // have them point to each other
    trailer->prev = header;
}

// Function to insert a new author while maintaining the sorted order
void DLinkedList::insert(const Elem &e)
{
    DNode *current = header->next;
    while (current != trailer && current->elem.nbooks < e.nbooks)
    {
        current = current->next;
    }

    DNode *newNode = new DNode(e);
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
}

// Function to display all authors in the list
void DLinkedList::displayAll()
{
    DNode *current = header->next;
    while (current != trailer)
    {
        current->elem.display();
        current = current->next;
    }
}

int main()
{
    DLinkedList authorsList;

    // Inserting authors
    Author author1("John Smith", 40, 3, {"Book 1", "Book 2", "Book 3"});
    Author author2("Jane Doe", 35, 2, {"Book A", "Book B"});
    Author author3("David Johnson", 50, 5, {"Book X", "Book Y", "Book Z", "Book W", "Book V"});

    authorsList.insert(author1);
    authorsList.insert(author2);
    authorsList.insert(author3);

    // Displaying the list of authors
    authorsList.displayAll();

    return 0;
}
