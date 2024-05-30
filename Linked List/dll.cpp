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
    Node *prev;
    Node *next;
    friend class Mylinkedlist;

public:
    Node() : prev(NULL), next(NULL) {}
    Node(int elem) : elem(elem), prev(NULL), next(NULL) {}
};
class Mylinkedlist
{
private:
    Node *header;
    Node *trailer;

public:
    Mylinkedlist()
    {
        header = new Node();
        trailer = new Node();
        header->next = trailer;
        trailer->prev = header;
    }
    bool is_empty()
    {
        return (header->next == trailer);
    }
    ~Mylinkedlist()
    {
        while (!is_empty())
        {
            removefront();
        }
        delete header;
        delete trailer;
    }
    void removefront()
    {
        if (is_empty())
        {
            throw runtime_error("The list is empty");
        }
        else
        {
            Node *old = header->next;
            header->next = old->next;
            old->next->prev = old->prev;
            delete old;
        }
    }
    void addfront(int elem)
    {
        Node *v = new Node(elem);
        v->prev = header;
        v->next = header->next;
        header->next->prev = v;
        header->next = v;
    }
    void addback(int elem)
    {
        Node *v = new Node(elem);
        v->next = trailer;
        v->prev = trailer->prev;
        trailer->prev->next = v;
        trailer->prev = v;
    }
    void removeback()
    {
        if (is_empty())
        {
            throw runtime_error("The list is empty");
        }
        else
        {
            Node *old = trailer->prev;
            trailer->prev = old->prev;
            old->prev->next = trailer;
        }
    }
    void display()
    {
        if (is_empty())
        {
            throw runtime_error("The list is empty");
        }
        else
        {
            Node *traversal = header->next;
            while (traversal != trailer)
            {
                cout << traversal->elem << " ";
                traversal = traversal->next;
            }
        }
        cout << endl;
    }
    void reverse()
    {
        Node *ptr1 = header->next;
        Node *ptr2 = ptr1->next;
        ptr1->next = trailer;
        ptr1->prev = ptr2;
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;

        while (!is_empty())
        {
        }
    }
};
int main()
{
    Mylinkedlist l1;
    l1.addfront(-44);
    l1.addfront(1123);
    l1.addfront(155);
    l1.addfront(11);
    l1.addfront(19);
    l1.addfront(20);
    l1.addfront(13);
    l1.removefront();
    l1.removeback();
    l1.addback(2213);
    l1.reverse();
    l1.display();

    return 0;
}