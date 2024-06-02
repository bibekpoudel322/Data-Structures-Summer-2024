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
    int elem; // data element (type int in this case)
    Node *next;
    Node *prev;
    friend class Mylinkedlist;

public:
    Node(int elem) : elem(elem), next(NULL), prev(NULL) {}
    Node() : next(NULL), prev(NULL) {}
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
        return header->next == trailer;
    }
    int front()
    {
        return header->next->elem;
    }
    int back()
    {
        return trailer->prev->elem;
    }
    void remove_front()
    {
        if (is_empty())
        {
            throw runtime_error("The list is empty");
        }
        Node *old = header->next;
        header->next = old->next;
        old->next->prev = header;
        delete old;
    }
    void add_front(int elem)
    {
        Node *newNode = new Node(elem);
        newNode->next = header->next;
        header->next = newNode;
        newNode->next->prev = newNode;
        newNode->prev = header;
    }
    void add_back(int elem)
    {
        Node *v = new Node(elem);
        v->next = trailer;
        v->prev = trailer->prev;
        trailer->prev->next = v;
        trailer->prev = v;
    }
    void remove_back()
    {
        if (is_empty())
        {
            throw logic_error("List is empty");
        }
        Node *old = trailer->prev;
        old->prev->next = trailer;
        trailer->prev = old->prev;
        delete old;
    }
    void display()
    {
        cout << "Elements in the list : ";
        if (is_empty())
        {
            throw logic_error("List is empty");
        }
        Node *traverse = header->next;
        while (traverse != trailer)
        {
            cout << traverse->elem << " ";
            traverse = traverse->next;
        }
        cout << endl;
    }
    ~Mylinkedlist()
    {
        while (!is_empty())
        {
            remove_front();
        }
        delete header;
        delete trailer;
    }
    void reverse()
    {
        cout << "Before reverse : " << endl;
        display();

        struct Node *temp = NULL;
        Node *current = header->next;
        Node *oldtrailer = trailer;
        trailer = header;

        while (current != oldtrailer)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        header->next = temp->prev;
        cout << "After reverse : " << endl;
        display();
    }
};

int main()
{
    Mylinkedlist myList;
    myList.add_front(5);
    myList.add_front(10);
    myList.add_back(15);
    myList.add_front(1115);
    myList.display(); // Expected output: Elements in the list : 10 5 15
    myList.reverse();
    return 0;
}