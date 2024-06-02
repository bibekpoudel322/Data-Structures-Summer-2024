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
    friend class circularlinkedlist;
    friend class linkedqueue;

public:
    Node(int elem) : elem(elem) {}
};
class circularlinkedlist
{
private:
    Node *cursor;
    int size;
    friend class linkedqueue;

public:
    circularlinkedlist()
    {
        cursor = NULL;
        size = 0;
    }
    bool is_empty()
    {
        return size == 0;
    }
    int front()
    {
        return cursor->next->elem;
    }
    void add(int elem)
    {
        Node *v = new Node(elem);
        if (size == 0)
        {
            v->next = v;
            cursor = v;
        }
        else
        {
            v->next = cursor->next;
            cursor->next = v;
        }
        size++;
    }
    void remove()
    {
        if (is_empty())
        {
            throw runtime_error("The queue is empty");
        }
        Node *old = cursor->next;
        if (old == cursor)
        {
            cursor->next = NULL;
        }
        else
        {
            cursor->next = old->next;
        }
        delete old;
    }
    void advance()
    {
        cursor = cursor->next;
    }
    int queue_size()
    {
        return size;
    }
};
class linkedqueue
{
private:
    circularlinkedlist l1;
    int elem;

public:
    linkedqueue(){};
    void enqueue(int elem)
    {
        l1.add(elem);
        l1.advance();
    }
    void dequeue()
    {
        l1.remove();
    }
    int front()
    {
        return l1.front();
    }
    int size()
    {
        return l1.queue_size();
    }
    void display()
    {
        Node *traversal = l1.cursor->next;
        while (traversal != NULL)
        {
            cout << traversal->elem << " ";
            if (traversal == l1.cursor)
            {
                traversal->next = NULL;
            }
            traversal = traversal->next;
        }
    }
};
int main()
{
    linkedqueue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.dequeue(); // Remove 10
    queue.dequeue(); // Remove 20
    queue.display();
    cout << "Queue is empty: " << (queue.size() == 0) << endl;
    return 0;
}