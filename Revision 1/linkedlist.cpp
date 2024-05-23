#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoubleLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    DoubleLinkedList dll;

    dll.insertAtBeginning(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtBeginning(0);

    dll.printList();

    return 0;
}