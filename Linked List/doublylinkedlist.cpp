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
    Node *previous;
    Node *next;
    friend class mylinkedlist;

public:
    Node(int elem) : elem(elem), previous(NULL), next(NULL) {}
};
class mylinkedlist
{
private:
    Node *header = NULL;
    Node *trailer = NULL;

public:
    ~mylinkedlist()
    {
        while (is_empty())
        {
            removeFront();
        }
    }
    void addFront(int elem)
    {
        Node *v = new Node(elem);
        if (header == NULL)
        {
            trailer = v;
            header = v;
        }
        else
        {
            v->next = header;
            header->previous = v;
            header = v;
        }
    }
    bool is_empty()
    {
        return header == NULL;
    }
    void display()
    {
        cout << endl;
        Node *traversal = header;
        while (traversal != NULL)
        {
            cout << traversal->elem << "-->";
            traversal = traversal->next;
        }
    }
    int front()
    {
        cout << endl;
        return header->elem;
    }
    int back()
    {
        cout << endl;
        return trailer->elem;
    }
    void addBack(int elem)
    {
        Node *v = new Node(elem);
        if (is_empty())
        {
            header = v;
            trailer = v;
        }
        else
        {
            v->previous = trailer;
            trailer->next = v;
            trailer = v;
        }
    }
    void removeFront()
    {
        if (header != NULL)
        {
            Node *traversal = header;
            header = header->next;
            header->previous = NULL;
            delete traversal;
        }
    }
    void removeBack()
    {
        if (trailer != nullptr)
        {
            Node *temp = trailer;
            trailer = trailer->previous;
            if (trailer != nullptr)
            {
                trailer->next = nullptr;
            }
            else
            {
                header = nullptr; // The list is now empty
            }
            delete temp;
        }
    }
    void add(Node *v, int el)
    {
        Node *x = new Node(el);
        Node *traversal = header;
        while (traversal != v)
        {
            traversal = traversal->next;
        }
        if (traversal == v)
        {
            if (traversal == header)
            {
                addFront(el);
            }
            else
            {
                Node *oldprevious = v->previous;
                x->next = v;
                x->previous = v->previous;
                v->previous = x;
                oldprevious->next = x;
            }
        }
    }
    void addinIndex(int index, int elem)
    {
        int i = 0;
        Node *x = new Node(elem);
        Node *traversal = header;
        while (i != index)
        {
            traversal = traversal->next;
            i++;
        }
        if (i == index)
        {
            if (index == 0)
            {
                addFront(elem);
            }
            else
            {
                x->next = traversal;
                x->previous = traversal->previous;
                traversal->previous->next = x;
                traversal->previous = x;
            }
        }
    }
    void remove()
    {
    }
};

int main()
{
    mylinkedlist m1;
    m1.addFront(12);
    m1.addFront(15);
    m1.addFront(19);
    m1.addFront(12);
    m1.addFront(44);
    m1.addFront(25);
    m1.display();
    cout << m1.front();
    cout << m1.back();
    m1.addBack(100);
    m1.addBack(111);
    m1.display();
    cout << m1.front();
    cout << m1.back();
    m1.removeFront();
    m1.display();
    m1.removeBack();
    m1.display();
    cout << m1.front();
    cout << m1.back();
    m1.addinIndex(5, -111);
    m1.display();
    return 0;
}