#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
class stack
{
private:
    int *arr;
    int capacity;
    int size;
    int top;

public:
    stack(int capacity)
    {
        this->capacity = capacity;
        arr = new int[capacity];
        size = 0;
        top = -1;
    }
    ~stack()
    {
        delete[] arr;
    }
    bool is_full()
    {
        return capacity == size;
    }
    bool is_empty()
    {
        return size == 0;
    }
    int t()
    {
        return top;
    }
    void push(int element)
    {
        if (is_full())
        {
            throw logic_error("Stack is Full. ");
        }
        arr[++top] = element;
        size++;
    }
    void pop()
    {
        if (is_empty())
        {
            throw logic_error("Stack is empty. ");
        }
        top--;
        size--;
    }
    void display()
    {
        if (is_empty())
        {
            throw logic_error("Stack is empty. ");
        }
        cout << "Elements in the stack: " << " ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    stack myStack(5);
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display(); // Expected output: Elements in the stack: 10 20 30
    myStack.pop();
    myStack.display(); // Expected output: Elements in the stack: 10 20

    stack boundaryStack(2); // Capacity set to 2
    boundaryStack.push(10);
    boundaryStack.push(20);
    boundaryStack.pop();
    boundaryStack.pop();
    boundaryStack.pop(); // Uncommenting this line should throw an exception (stack empty)

    return 0;
}