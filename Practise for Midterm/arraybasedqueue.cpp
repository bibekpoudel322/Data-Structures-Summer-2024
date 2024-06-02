#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;

class Queue
{
private:
    int *arr;
    int size;
    int capacity;
    int frontIndex;
    int rearIndex;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int(capacity);
        size = 0;
        frontIndex = rearIndex = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    bool empty()
    {
        return size == 0;
    }
    bool full()
    {
        return size == capacity;
    }
    void enqueue(int element)
    {
        if (full())
        {
            throw logic_error("Queue is full");
        }
        arr[rearIndex] = element;
        rearIndex = (rearIndex + 1) % capacity;
        size++;
    }
    void dequeue()
    {
        if (empty())
        {
            throw logic_error("Queue is empty");
        }
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }
    int size_of_queue()
    {
        return size;
    }
    int front()
    {
        return arr[frontIndex];
    }
    void display()
    {
        int traversal = frontIndex;
        cout << endl;
        cout << "Elements in the queue : " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[traversal] << " ";
            traversal = (traversal + 1) % capacity;
        }
    }
};
int main()
{
    Queue myqueue(5);
    myqueue.enqueue(1);
    myqueue.enqueue(1123);
    myqueue.enqueue(130);
    cout << "Size of the queue is: " << myqueue.size_of_queue() << endl;
    myqueue.display();
    myqueue.dequeue();
    myqueue.display();
    cout << "Size of the queue is: " << myqueue.size_of_queue() << endl;
    return 0;
}