#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;

// creation of a linked list

class Node
{
private:
    int elem;
    Node *next;

public:
    Node(int elem) : elem(elem), next(NULL) {}
    friend class Mylinkedlist;
};

class Mylinkedlist
{
private:
    Node *head;

public:
    Mylinkedlist() : head(NULL) {}
    void addFront(int elem)
    {
        Node *v = new Node(elem); // make a new node with
        v->next = head;
        head = v; // set head pointing to the address of the v
    }
    void removeFront()
    {
        Node *old = head; // Make a flag old to store the head as it is the only way to acess that
        head = old->next; // update the head
        delete old;       // delete the old
    }
    ~Mylinkedlist()
    {
        while (!isempty())
        {
            removeFront();
        }
    }
    bool isempty()
    {
        return head == NULL;
    }
    void displaynode()
    {
        Node *v = head;
        cout << "Head-->";
        while (v->next != NULL)
        {
            cout << v->elem << "-->";
            v = v->next;
        }
    }
};
int main()
{
    Mylinkedlist m1;
    m1.addFront(1);
    m1.addFront(3);
    m1.addFront(6);
    m1.addFront(9);
    m1.displaynode();
    cout << endl;
    m1.removeFront();
    m1.displaynode();
    return 0;
}