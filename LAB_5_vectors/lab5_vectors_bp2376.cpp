//============================================================================
// Name         : MyVector.cpp
// Author       : Bibek poudel
// Version      : 1.0
// Date Created : 6/6/2024
// Date Modified:
// Description  : Vector implmentation in C++
//============================================================================
// start_code+begins
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <stdexcept>
#include <sstream>

using namespace std;

template <typename T>
class MyVector
{
private:
    T *data;        // pointer to int(array) to store elements
    int v_size;     // current size of vector (number of elements in vector)
    int v_capacity; // capacity of vector
public:
    MyVector(int cap = 0);             // Constructor
    ~MyVector();                       // Destructor
    int size() const;                  // Return current size of vector
    int capacity() const;              // Return capacity of vector
    bool isEmpty() const;              // Rturn true if the vector is empty, False otherwise
    const T &front();                  // Returns reference of the first element in the vector
    const T &back();                   // Returns reference of the Last element in the vector
    void push_back(T element);         // Add an element at the end of vector
    void insert(int index, T element); // Add an element at the index
    void erase(int index);             // Removes an element from the index
    T &operator[](int index);          // Returns the reference of an element at given index
    T &at(int index);                  // return reference of the element at given index
    void shrink_to_fit();              // Reduce vector capacity to fit its size
    void display();
};

void listCommands()
{
    cout << "List of available Commands:" << endl
         << "display                  : Display the Vector" << endl
         << "push_back <element>      : Add an element to the end of the vector" << endl
         << "insert <index element>   : Insert an element at location index" << endl
         << "erase <index>            : Remove the element from index" << endl
         << "[index]                  : Returns a reference to an element at a specified index" << endl
         << "at <index>               : Returns a reference to an element at a specified index" << endl
         << "front                    : Return the (reference of) front element" << endl
         << "back                     : Returns a reference to the last element of the vector" << endl
         << "size                     : Returns the number of elements in the vector" << endl
         << "capacity                 : Returns the capacity of vector" << endl
         << "isEmpty                  : Tests if the vector container is empty" << endl
         << "shrink                   : Reduce vector capacity to fit its size (shrink_to_fit)" << endl
         << "exit/quit                : Exit the Program" << endl;
}
//=======================================
int main()
{

    MyVector<int> myVector;
    // unitTest();
    string user_input;
    string command;
    string parameter1;
    string parameter2;
    listCommands();

    do
    {
        cout << ">";
        getline(cin, user_input);

        // parse userinput into command and parameter(s)
        stringstream sstr(user_input);
        getline(sstr, command, ' ');
        getline(sstr, parameter1, ' ');
        getline(sstr, parameter2);

        try
        {
            if (command == "display" or command == "d")
                myVector.display();
            else if (command == "push_back" or command == "p")
                myVector.push_back(stoi(parameter1)), myVector.display();
            else if (command == "insert" or command == "i")
                myVector.insert(stoi(parameter1), stoi(parameter2)), myVector.display();
            else if (command == "erase" or command == "e")
                myVector.erase(stoi(parameter1)), myVector.display();
            else if (command == "at" or command == "a")
                cout << myVector.at(stoi(parameter1)) << endl;
            else if (command[0] == '[' and command[command.length() - 1] == ']')
                cout << myVector[stoi(command.substr(1, command.length() - 2) + "")] << endl;
            else if (command == "front" or command == "f")
                cout << myVector.front() << endl;
            else if (command == "back" or command == "b")
                cout << myVector.back() << endl;
            else if (command == "size" or command == "s")
                cout << myVector.size() << endl;
            else if (command == "capacity" or command == "c")
                cout << myVector.capacity() << endl;
            else if (command == "isEmpty" or command == "ie")
                cout << boolalpha << myVector.isEmpty() << endl;
            else if (command == "shrink")
                myVector.shrink_to_fit(), myVector.display();
            else if (command == "help" or command == "?")
                listCommands();
            else if (command == "exit" or command == "quit")
                break;
            else
                cout << "Invalid Commad !!" << endl;
        }
        catch (exception &e)
        {
            cout << "Exception: " << e.what() << endl;
        }

    } while (command != "exit" and command != "quit");

    return EXIT_SUCCESS;
}
//======================================
#ifndef _WIN32
//======================================
template <typename T>
void MyVector<T>::display()
{
    cout << "╔";

    for (int i = 0; i < v_capacity; i++)
    {
        cout << "════";
        if (i != v_capacity - 1)
            cout << "╦";
    }
    cout << "╗ size = " << v_size << endl;

    for (int i = 0; i < v_capacity; i++)
    {
        cout << "║";
        if (i < v_size)
            cout << setw(4) << data[i];
        else
            cout << setw(4) << " ";
    }
    if (v_capacity == 0)
        cout << "║";
    cout << "║" << endl
         << "╚";
    for (int i = 0; i < v_capacity; i++)
    {
        cout << "════";
        if (i != v_capacity - 1)
            cout << "╩";
    }
    cout << "╝ capacity = " << v_capacity << endl;
}
//======================================
#else
template <typename T>
void MyVector<T>::display()
{
    cout << "+";

    for (int i = 0; i < v_capacity; i++)
    {
        cout << "----";
        if (i != v_capacity - 1)
            cout << "+";
    }
    cout << "+ size = " << v_size << endl;

    for (int i = 0; i < v_capacity; i++)
    {
        cout << "|";
        if (i < v_size)
            cout << setw(4) << data[i];
        else
            cout << setw(4) << " ";
    }
    if (v_capacity == 0)
        cout << "|";
    cout << "|" << endl
         << "+";
    for (int i = 0; i < v_capacity; i++)
    {
        cout << "----";
        if (i != v_capacity - 1)
            cout << "+";
    }
    cout << "+ capacity = " << v_capacity << endl;
}
#endif
// starter-code-ends
//======================================
template <typename T>
MyVector<T>::MyVector(int cap)
{
    v_capacity = cap;         // set the capacity of vector
    v_size = 0;               // set the size of vector, initially 0
    data = new T[v_capacity]; // allocate memory for the vector
}
//======================================
template <typename T>
MyVector<T>::~MyVector()
{
    delete[] data; // deallocate memory
}
//======================================
template <typename T>
int MyVector<T>::size() const
{
    return v_size; // return the size of vector
}
//======================================
template <typename T>
int MyVector<T>::capacity() const
{
    return v_capacity; // return the capacity of vector
}
//======================================
template <typename T>
bool MyVector<T>::isEmpty() const
{
    return v_size == 0; // return true if vector is empty, false otherwise
}
//======================================
class VectorEmpty : public std::exception // custom class for exception handling
{
public:
    virtual const char *what() const throw()
    {
        return "Vector is Empty"; // Provide a message for the exception
    }
};
template <typename T>
const T &MyVector<T>::front()
{
    if (isEmpty())
    {
        throw out_of_range("Vector is Empty.."); // throw an exception if vector is empty
    }
    else
    {
        return data[0]; // return the first element of vector
    }
}
//======================================
template <typename T>
const T &MyVector<T>::back()
{
    if (isEmpty())
    {
        throw out_of_range("Vector is Empty.."); // throw an exception if vector is empty
    }
    else
    {
        return data[v_size - 1]; // return the last element of vector
    }
}
//======================================
template <typename T>
void MyVector<T>::push_back(T element)
{
    if (v_size == v_capacity)
    {
        v_capacity = v_capacity == 0 ? 1 : v_capacity * 2; // double the capacity if vector is full
        T *temp = new T[v_capacity];                       // allocate memory for new vector
        for (int i = 0; i < v_size; i++)
        {
            temp[i] = data[i]; // copy the elements of old vector to new vector
        }
        delete[] data; // deallocate memory of old vector
        data = temp;   // assign the new vector to old vector
    }
    data[v_size++] = element; // add the element to the end of vector
}
//======================================
template <typename T>
void MyVector<T>::insert(int index, T element)
{
    if (index < 0 || index >= v_size)
    {
        throw out_of_range("Vector index out of range...!"); // throw an exception if index is out of range
    }
    if (v_size == v_capacity)
    {
        v_capacity = v_capacity == 0 ? 1 : v_capacity * 2; // double the capacity if vector is full
        T *temp = new T[v_capacity];                       // allocate memory for new vector
        for (int i = 0; i < v_size; i++)
        {
            temp[i] = data[i]; // copy the elements of old vector to new vector
        }
        delete[] data; // deallocate memory of old vector
        data = temp;   // assign the new vector to old vector
    }
    for (int i = v_size; i > index; i--)
    {
        data[i] = data[i - 1]; // shift the elements to right
    }
    data[index] = element; // insert the element at the index
    v_size++;              // increment the size of vector
}
//======================================
template <typename T>
void MyVector<T>::erase(int index)
{
    if (index < 0 || index >= v_size)
    {
        throw out_of_range("Index out of range"); // throw an exception if index is out of range
    }
    for (int i = index; i < v_size - 1; i++)
    {
        data[i] = data[i + 1]; // shift the elements to left
    }
    v_size--; // decrement the size of vector
}
//======================================
template <typename T>
T &MyVector<T>::operator[](int index)
{
    if (index < 0 || index >= v_size)
    {
        throw out_of_range("Index out of range"); // throw an exception if index is out of range
    }
    return data[index]; // return the reference of element at given index
}
//======================================
template <typename T>
T &MyVector<T>::at(int index)
{
    if (index < 0 || index >= v_size)
    {
        throw out_of_range("Vector Index out of range...!"); // throw an exception if index is out of range
    }
    return data[index]; // return the reference of element at given index
}
//======================================
template <typename T>
void MyVector<T>::shrink_to_fit()
{
    if (v_capacity > v_size)
    {
        v_capacity = v_size; // set the capacity of vector to its size
        T *temp = new T[v_capacity];
        for (int i = 0; i < v_size; i++)
        {
            temp[i] = data[i]; // copy the elements of old vector to new vector
        }
        delete[] data; // deallocate memory of old vector
        data = temp;   // assign the new vector to old vector
    }
}
//======================================
// end_code+ends