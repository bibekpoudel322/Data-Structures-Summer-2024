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
    int size;

public:
    Circularlinkedlist()
    {
        cursor = NULL;
        size = 0;
    }
    ~Circularlinkedlist()
    {
        while (!is_empty())
        {
            remove();
        }
    }
    bool is_empty()
    {
        return cursor == NULL;
    }
    void add(int elem)
    {
        Node *v = new Node(elem);
        if (is_empty())
        {
            v->next = v;
            cursor = v;
        }
        else
        {
            v->next = cursor->next;
            cursor->next = v;
        }
    }
    void remove()
    {
        if (cursor->next == cursor) // If there's only one element in the list
        {
            cursor = NULL;
        }
        if (is_empty())
        {
            throw runtime_error("The list is empty");
        }
        Node *old = cursor->next;
        cursor->next = old->next;
        delete old;
        if (is_empty())
        {
            cursor = cursor->next = NULL;
            throw runtime_error("The list is empty");
        }
    }
    void advance()
    {
        cursor = cursor->next;
    }
    void display()
    {
        cout << "The contents in the list are: ";
        Node *traversal = cursor->next;
        while (traversal != cursor)
        {
            cout << traversal->elem << " ";
            traversal = traversal->next;
        }
        if (traversal == cursor)
        {
            cout << traversal->elem;
        }
        cout << endl;
    }
};
int main()
{
    Circularlinkedlist myList;
    myList.add(5);
    myList.add(10);
    myList.add(15);
    myList.remove();
    myList.remove();
    myList.remove();
    // Attempting to remove from an empty list should throw an exception
    return 0;
}