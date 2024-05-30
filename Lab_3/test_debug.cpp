#include <iostream>
#include <stdexcept>

template <typename T>
class MyStack
{
private:
    T *array;
    int n; // number of current elements in the MyStack
    int N; // Array Size (Capacity)
public:
    MyStack(int N = 50); // we set default capacity of stack as 50
    ~MyStack();
    void push(T); // Push an elemet in the stack
    void pop();   // pop/remove the element at the tos
    T &top();     // return reference of the top element
    int size();   // return current size of MyStack
    bool empty(); // returns true if the stack is Empty
    void display();
};

template <typename T>
MyStack<T>::MyStack(int N)
{
    this->N = N;
    array = new T[N];
    n = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
    delete[] array;
}

template <typename T>
void MyStack<T>::push(T elem)
{
    if (n == N)
        throw std::logic_error("Stack Overflow");
    array[n++] = elem;
}

template <typename T>
void MyStack<T>::pop()
{
    if (n == 0)
        throw std::logic_error("Stack Underflow");
    n--;
}

template <typename T>
T &MyStack<T>::top()
{
    if (n == 0)
        throw std::logic_error("Stack is Empty");
    return array[n - 1];
}

template <typename T>
int MyStack<T>::size()
{
    return n;
}

template <typename T>
bool MyStack<T>::empty()
{
    return n == 0;
}
template <typename T>
void MyStack<T>::display()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // Test Case 1: Create an integer stack
    MyStack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.display(); // Should print 1 2 3
    std::cout << std::endl;
    std::cout << "Top of intStack: " << intStack.top() << std::endl;     // Should print 3
    std::cout << "Size of intStack: " << intStack.size() << std::endl;   // Should print 2
    std::cout << "Is intStack Empty: " << intStack.empty() << std::endl; // Should print 0
    intStack.push(4);
    intStack.push(88);
    intStack.push(499);

    return 0;
}
