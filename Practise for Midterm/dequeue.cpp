#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
class Node
{
private:
    int elem;
    Node *next;
    Node *previous;
    friend class doublelinkedlist;

public:
    Node(int elem) : elem(elem), next(NULL), previous(NULL) {}
    Node(){};
};
class doublelinkedlist
{
private:
    Node *header;
    Node *trailer;

public:
    doublelinkedlist()
    {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->previous = header;
    }
    bool is_empty()
    {
        return header->next == trailer;
    }
    void add_front(int element)
    {
        Node *v = new Node(element);
        v->next = header->next;
        v->previous = header;
        header->next->previous = v;
        header->next = v;
    }
    void add_back(int element)
    {
        Node *v = new Node(element);
        v->next = trailer;
        v->previous = trailer->previous;
        trailer->previous->next = v;
        trailer->previous = v;
    }
    void remove_front()
    {
        if (is_empty())
        {
            throw logic_error("List is empty");
        }
        Node *old = header->next;
        header->next = old->next;
        old->next->previous = header;
        delete old;
    }
    void remove_back()
    {
        if (is_empty())
        {
            throw logic_error("List is empty");
        }
        Node *old = trailer->previous;
        old->previous->next = trailer;
        trailer->previous = old->previous;
        delete old;
    }
    int front()
    {
        return header->next->elem;
    }
    int back()
    {
        return trailer->previous->elem;
    }
    void display()
    {
        cout << "Elements in the queue is : " << endl;
        Node *traversal = header->next;
        while (traversal != trailer)
        {
            cout << traversal->elem << " ";
            traversal = traversal->next;
        }
        cout << endl;
    }
};
class Dequeue
{
private:
    doublelinkedlist d1;

public:
    Dequeue(){};
    void insertFront(int e)
    {
        d1.add_front(e);
    }
    void insertBack(int e)
    {
        d1.add_back(e);
    }
    void eraseFront()
    {
        d1.remove_front();
    }
    void eraseBack()
    {
        d1.remove_back();
    }
    void show()
    {
        d1.display();
    }
};
int main()
{

    // Create a deque object
    Dequeue dq;

    // Test inserting elements at the front
    dq.insertFront(10);
    dq.insertFront(20);
    dq.show(); // Expected output: 20 10

    // Test inserting elements at the back
    dq.insertBack(30);
    dq.insertBack(40);
    dq.show(); // Expected output: 20 10 30 40

    // Test removing elements from the front
    dq.eraseFront();
    dq.show(); // Expected output: 10 30 40

    // Test removing elements from the back
    dq.eraseBack();
    dq.show(); // Expected output: 10 30

    return 0;
}