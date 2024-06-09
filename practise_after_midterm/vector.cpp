#include <iostream>
#include <list>
#include <fstream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
// vector implementation

class myvector
{
private:
    int *array;
    int capacity;
    int size;

public:
    myvector(int capacity)
    {
        this->capacity = capacity;
        array = new int[capacity];
        size = 0;
    }
    int at(int index)
    {
        return array[index];
    }
    int operator[](int index)
    {
        return array[index];
    }
    bool is_empty()
    {
        return size == 0;
    }
    void reserve()
    {
        if (capacity == 0)
        {
            capacity == 1;
        }
        else
        {
            capacity = capacity * 2;
        }
        int *temp = new int[capacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }
    void insert(int index, int element)
    {
        if (index < 0 || index > size)
        {
            throw out_of_range("Index out of range");
        }
        else
        {
            if (size >= capacity)
            {
                reserve();
            }
            for (int i = size; i > index; i--)
            {
                array[i] = array[i - 1];
            }
            array[index] = element;
            size++;
        }
    }
    void remove(int index)
    {
        if (is_empty())
        {
            throw logic_error("The list is empty");
        }
        for (int i = index; i < size; i++)
        {
            array[i] = array[i + 1];
        }
        size--;
    }
    void display()
    {
        cout << "Elements in the vector: \n";
        for (int i = 0; i < size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    ~myvector()
    {
        delete[] array;
    }
};
int main()
{
    myvector v(3);
    v.insert(0, 1);
    v.insert(1, 2);
    v.insert(2, 3);
    v.remove(1);
    v.display(); // Expected output: Elements in the vector: 1 2 3
    v.display(); // Expected output: Elements in the vector: 1 2 3 4
    return 0;
}