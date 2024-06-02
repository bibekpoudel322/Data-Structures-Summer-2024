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
    int size;
    int capacity;
    int frontIndex;
    int backIndex;
    int *arr;

public:
    Queue(int capacity)
    {
        this->capacity = capacity;
        arr = new int(capacity);
        frontIndex = backIndex = size = 0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size == 0;
    }
    int front()
    {
        if (isempty())
        {
            throw runtime_error("Queue is empty");
        }
        else
        {
            return arr[frontIndex];
        }
    }
    int rear()
    {
        if (isempty())
        {
            throw runtime_error("Queue is empty");
        }
        else
        {
            return arr[backIndex];
        }
    }
    bool is_full()
    {
        return size >= capacity;
    }
    void enqueue(int element)
    {
        if (is_full())
        {
            throw runtime_error("The queue is full");
        }
        arr[backIndex] = element;
        size++;
        backIndex = (backIndex + 1) % capacity;
    }
    void dequeue()
    {
        if (isempty())
        {
            throw runtime_error("The queue is empty");
        }
        frontIndex = (frontIndex + 1) % capacity;
        size--;
    }
    void display()
    {
        if (isempty())
        {
            throw runtime_error("Queue is Empty");
        }
        int k = frontIndex;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[k] << " ";
            k = (k + 1) % capacity;
        }
        cout << endl;
    }
    void reverse()
    {
        int *newarray = new int(size);
        int traversal = backIndex;
        for (int i = 0; i < size; i++)
        {
            newarray[i] = arr[traversal];
            size++;
            if (traversal == 0)
            {
                traversal = capacity;
            }
            else
            {
                traversal = (traversal - 1) % capacity;
            }
        }
        delete[] arr;
        arr = newarray;
        frontIndex = 0;
        backIndex = size - 1;
    }
};
int main()
{
    Queue q1(5);
    q1.enqueue(334);
    q1.enqueue(223);
    q1.enqueue(3124);
    q1.enqueue(345);
    q1.enqueue(32235);
    q1.display();
    cout << "Front of the element is : " << q1.front() << endl;
    q1.dequeue();
    q1.dequeue();
    q1.display();
    cout << "Front of the element is : " << q1.front() << endl;
    q1.enqueue(-1);
    q1.display();
    cout << "Front of the element is : " << q1.front() << endl;
    q1.reverse();
    q1.display();

    return 0;
}