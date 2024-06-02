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
int main()
{
    Mylinkedlist list;
    list.addFront(5);
    list.addFront(10);
    list.addFront(15);
    list.insert_after(10, 66);
    cout << "Front of the element is : " << list.front();
    return 0;
}