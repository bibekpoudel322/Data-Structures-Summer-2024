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
    friend class mystack;

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
    int size()
    {
        int counter = 0;
        Node *traversal = head;
        while (traversal != NULL)
        {
            counter++;
            traversal = traversal->next;
        }
        return counter;
    }
};
class Mystack
{
private:
    Linkedlist l1;

public:
    Mystack()
    {
    }
    void push(int elem)
    {
        l1.addFront(elem);
    }
    void pop()
    {
        l1.removeFront();
    }
    int top()
    {
        return l1.front();
    }
    int size()
    {
        return l1.size();
    }
    void display()
    {
        l1.display();
    }
};
int main()
{

    // Create a stack
    Mystack stack;

    // Test case 1: Pushing elements onto the stack
    cout << "Test Case 1: Pushing elements onto the stack" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.display();
    cout << "Size of stack: " << stack.size() << endl; // Expected output: Size of stack: 3

    // Test case 2: Popping elements from the stack
    cout << "\nTest Case 2: Popping elements from the stack" << endl;
    cout << "Top element before popping: " << stack.top() << endl; // Expected output: Top element before popping: 30
    stack.pop();
    cout << "Top element after popping: " << stack.top() << endl;    // Expected output: Top element after popping: 20
    cout << "Size of stack after popping: " << stack.size() << endl; // Expected output: Size of stack after popping: 2

    // Test case 3: Popping from an empty stack

    // Test case 4: Pushing more elements to fill the stack
    cout << "\nTest Case 4: Pushing more elements to fill the stack" << endl;
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.display();
    cout << "Size of stack after pushing more elements: " << stack.size() << endl; // Expected output: Size of stack after pushing more elements: 5

    return 0;
}
