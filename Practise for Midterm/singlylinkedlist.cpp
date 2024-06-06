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
        if (is_empty())
        {
            throw logic_error("The list is empty");
        }
        Node *next = NULL;
        Node *current = header;
        Node *previous = NULL;
        while (current != NULL)
        {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        header = previous;
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
    int middle()
    {
        Node *fast = header;
        Node *slower = header;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slower = slower->next;
        }
        return slower->elem;
    }
    int rotate(int k)
    {
        if (is_empty())
        {
            throw logic_error("The list is empty");
        }
        int size = 0;
        Node *traversal = header;
        while (traversal != NULL)
        {
            size++;
            traversal = traversal->next;
        }
        traversal = header;
        for (int i = 0; i < size - k; i++)
        {
            traversal = traversal->next;
        }
        while (traversal != NULL)
        {
            addFront(traversal->elem);
            traversal = traversal->next;
        }
    }
    void remove_duplicates()
    {
        Node *current = header;
        while (current != NULL)
        {
            Node *traversal = current->next;
            Node *previous = NULL;
            while (traversal != NULL)
            {
                if (traversal->elem == current->elem)
                {
                    if (traversal == header)
                    {
                        header = traversal->next;
                        delete traversal;
                        traversal = header; // Move traversal to the new header
                    }
                    else
                    {
                        Node *old = traversal;
                        previous->next = old->next;
                        traversal = previous->next; // Move traversal to the next node after deletion
                        delete old;
                    }
                }
                else
                {
                    previous = traversal; // Move previous pointer only when not deleting
                    traversal = traversal->next;
                }
            }
            current = current->next;
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
    list.addFront(12);
    list.addFront(5);
    list.display();
    list.remove_duplicates();
    list.display();
    return 0;
}