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
    friend class Mylinkedlist;

public:
    Node(int elem) : elem(elem), next(NULL) {}
};
class Mylinkedlist
{
private:
    Node *header;

public:
    Mylinkedlist() : header(NULL) {}
    ~Mylinkedlist()
    {
        while (!is_empty())
        {
            removeFront();
        }
    }
    bool is_empty()
    {
        return header == NULL;
    }
    void addFront(int elem)
    {
        Node *v = new Node(elem);
        v->next = header;
        header = v;
    }
    void removeFront()
    {
        if (is_empty())
        {
            throw logic_error("List is empty");
        }
        Node *old = header;
        header = old->next;
        delete old;
    }
    void display()
    {
        cout << "Elements in the list : ";
        {
            Node *traversal = header;
            while (traversal != NULL)
            {
                cout << traversal->elem << " ";
                traversal = traversal->next;
            }
        }
        cout << endl;
    }
    int front()
    {
        return header->elem;
    }
    void reverse()
    {
        Node *previous = NULL;
        Node *current = header;
        Node *next = NULL;
        if (is_empty())
        {
            throw logic_error("List is empty");
        }
        while (current != NULL)
        {
            if (current->next == NULL)
            {
                header = current;
            }
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
    }
    void insert_after(int element, int whatt)
    {
        Node *v = new Node(whatt);
        int index = 0;
        Node *traversal = header;
        while (traversal->elem != element)
        {
            traversal = traversal->next;
        }
        if (traversal->elem == element)
        {
            v->next = traversal->next;
            traversal->next = v;
        }
        else
        {
            cout << "Element not found" << endl;
        }
    }
};
class Stack
{
private:
    int size;
    Mylinkedlist l1;

public:
    Stack()
    {
        size = 0;
    }
    ~Stack()
    {
    }
    void push(int element)
    {
        l1.addFront(element);
        size++;
    }
    void pop()
    {
        l1.removeFront();
        size--;
    }
    int t()
    {
        return l1.front();
    }
    void display()
    {
        l1.display();
    }
    void reverse()
    {
        Stack s2;
        while (!l1.is_empty())
        {
            s2.l1.addFront(l1.front());
            {
                l1.removeFront();
            }
        }
        s2.display();
    }
};
int main()
{
    Stack myStack;
    int num;
    // Binary Implementation of stack;
    cout
        << "Enter a number to evaluate binary";
    cin >> num;
    while (num != 0)
    {
        myStack.push(num % 2);
        num = num / 2;
    }
    myStack.display();
    return 0;
}