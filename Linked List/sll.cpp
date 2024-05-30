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
    friend class Linkedlist;

private:
    Node(int elem) : elem(elem), next(NULL) {}
};
class Linkedlist
{
private:
    Node *head;

public:
    Linkedlist() : head(NULL) {}
    ~Linkedlist()
    {
        while (!empty())
        {
            removeFront();
        }
    }
    bool empty()
    {
        return head == NULL;
    }
    int front()
    {
        return head->elem;
    }
    void addFront(int elem)
    {
        Node *v = new Node(elem);
        v->next = head;
        head = v;
    }
    void removeFront()
    {
        if (empty())
        {
            throw runtime_error("Empty List");
        }
        else
        {
            Node *old = head;
            head = head->next;
            delete old;
        }
    }
    void display()
    {
        Node *traversal = head;
        while (traversal != NULL)
        {
            cout << traversal->elem << " ";
            traversal = traversal->next;
        }
    }
    void reverse()
    {
        if (empty() || head->next == NULL)
        {
            return; // No need to reverse if the list is empty or has only one element
        }

        Node *prev = NULL;
        Node *current = head;
        Node *nextNode = NULL;

        while (current != NULL)
        {
            nextNode = current->next; // Store next node
            current->next = prev;     // Reverse the pointer

            // Move pointers one position ahead
            prev = current;
            current = nextNode;
        }

        head = prev; // Update the head to point to the new first node (which was the last node before reversing)
    }
    int middle()
    {
        Node *slow = head;
        Node *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->elem;
    }
    int numberOfNodes()
    {
        Node *traversal = head;
        int count = 0;
        while (traversal != NULL)
        {
            count++;
            traversal = traversal->next;
        }
        return count;
    }
    void addback(int elem)
    {
        Node *traversal = head;
        while (traversal->next != NULL)
        {
            traversal->next = traversal;
        }
        Node *v = new Node(elem);
        traversal->next = v;
    }
    void addbefore(int elem, int after)
    {
        Node *traversal = head;
        while (traversal != NULL && traversal->next->elem != after)
        {
            traversal = traversal->next;
        }
        if (traversal == NULL)
        {
            throw runtime_error("Element not found");
        }
        Node *v = new Node(elem);
        v->next = traversal->next;
        traversal->next = v;
    }
    void deleteelem(int elem)
    {
        Node *traversal = head;
        while (traversal != NULL && traversal->next->elem != elem)
        {
            traversal = traversal->next;
        }
        if (traversal == NULL)
        {
            throw runtime_error("Element not found");
        }
        Node *temp = traversal->next;
        traversal->next = temp->next;
        delete temp;
    }
    void deletenthnode(int n)
    {
        Node *traversal = head;
        int count = 1;
        while (traversal != NULL && count != n - 1)
        {
            traversal = traversal->next;
            count++;
        }
        if (traversal == NULL)
        {
            throw runtime_error("Element not found");
        }
        Node *temp = traversal->next;
        traversal->next = temp->next;
        delete temp;
    }
};

int main()
{
    // Create an empty linked list
    Linkedlist list;

    // Test empty() function
    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl;

    // Test addFront() function
    list.addFront(5);
    list.addback(2);
    list.addFront(10);
    list.addFront(15);
    list.addFront(20);
    list.addFront(25);
    list.addFront(20);
    list.addbefore(1123, 2);
    list.deleteelem(2);

    // Test front() function
    cout << "Front element of the list: " << list.front() << endl;

    // Test display() function
    cout << "List elements: ";
    list.display();
    cout << endl;

    // Test removeFront() function
    list.removeFront();

    // Test display() function after removing an element
    cout << "List elements after removing front: ";
    list.display();
    cout << endl;

    // Test empty() function after removing an element
    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl;
    cout << "Reversed List: " << endl;
    list.display();
    cout << "Middle of the node is : " << list.middle() << endl;
    cout << "Number of nodes in the list: " << list.numberOfNodes() << endl;
    return 0;
}