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
    friend class Circularlinkedlist;

public:
    Node(int elem) : elem(elem), next(NULL) {}
};
class Circularlinkedlist
{
private:
    Node *cursor;

public:
    Circularlinkedlist()
    {
        cursor = NULL;
    }
    void advance()
    {
        cursor = cursor->next;
    }
    bool empty()
    {
        return cursor == NULL;
    }
    void add(int elem)
    {
        Node *v = new Node(elem);
        if (cursor == NULL)
        {
            v->next = v;
            cursor = v;
        }
        v->next = cursor->next;
        cursor->next = v;
    }
    void remove()
    {
        Node *old = cursor->next;
        if (cursor == cursor->next)
        {
            cursor = NULL;
        }
        cursor->next = old->next;
        delete old;
    }
    virtual void display()
    {
        if (empty())
        {
            throw logic_error("List is empty");
        }
        Node *traversal = cursor->next;
        while (traversal != cursor)
        {
            cout << traversal->elem << " ";
            traversal = traversal->next;
        }
        if (traversal == cursor)
        {
            cout << traversal->elem << endl;
        }
    }
};
class Queue
{
private:
    int size;
    int capacity;
    Circularlinkedlist c1;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        size = 0;
    }
    void enqueue(int elem)
    {
        if (size == capacity)
        {
            throw logic_error("Queue is full");
        }
        c1.add(elem);
        c1.advance();
        size++;
    }
    void dequeue()
    {
        if (size == 0)
        {
            throw logic_error("Queue is empty");
        }
        c1.remove();
        size--;
    }
    void display()
    {
        cout << "Items in the queue: ";
        c1.display();
    }
};
int main()
{
    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout << "Test Case 1: Enqueue elements and display" << endl;
    q1.display();
    q1.dequeue();
    q1.display();
    return 0;
}