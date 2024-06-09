#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;

class vectorm
{
private:
    int sizemmmmm;
    int capacity;
    int *array;

public:
    vectorm(int capacity)
    {
        this->capacity = capacity;
        sizemmmmm = 0;
        array = new int[capacity];
    };
    vectorm() : capacity(0), sizemmmmm(0){};
    ~vectorm()
    {
        delete[] array;
    }
    bool is_empty()
    {
        return sizemmmmm == 0;
    }
    int at(int index)
    {
        if (index < 0 || index >= sizemmmmm)
        {
            throw out_of_range("Vector Index out of Range.");
        }
        return array[index];
    }
    int size()
    {
        return sizemmmmm;
    }
    int capacityy()
    {
        return capacity;
    }
    void set(int index, int element)
    {
        if (index < 0 || index >= sizemmmmm)
        {
            throw out_of_range("Vector Index out of Range.");
        }
        array[index] = element;
    }
    int operator[](int index)
    {
        if (index < 0 || index >= sizemmmmm)
        {
            throw out_of_range("Vector Index out of Range.");
        }
        return array[index];
    }
    void reserve()
    {
        if (capacity == 0)
        {
            capacity = 1;
        }
        else
        {
            capacity = capacity * 2;
        }
        int *temp = new int[capacity];
        for (int i = 0; i < sizemmmmm; i++)
        {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
    }
    void display()
    {
        cout << "Elements in the vector : ";
        for (int i = 0; i < sizemmmmm; i++)
        {
            cout << array[i] << "   ";
        }
    }
    void insert(int index, int element)
    {
        if (index < 0 || index >= sizemmmmm)
        {
            throw out_of_range("Vector Index out of Range");
        }
        if (sizemmmmm == capacity)
        {
            reserve();
        }
        else
        {
            for (int i = sizemmmmm; i > index; i--)
            {
                array[i] = array[i - 1];
            }
            array[index] = element;
            sizemmmmm++;
        }
    }
    void erase(int index)
    {
        if (index < 0 || index >= sizemmmmm)
        {
            throw out_of_range("Vector Index out of Range");
        }
        else
        {
            for (int i = index; i < sizemmmmm; i++)
            {
                array[i] = array[i + 1];
            }
            sizemmmmm--;
        }
    }
    void push_back(int element)
    {
        if (sizemmmmm == capacity)
        {
            reserve();
            array[sizemmmmm] = element;
            sizemmmmm++;
        }
        else
        {
            array[sizemmmmm] = element;
            sizemmmmm++;
        }
    }
    void shrink()
    {
        if (sizemmmmm != capacity)
        {
            int *temp = new int[sizemmmmm];
            for (int i = 0; i < sizemmmmm; i++)
            {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
            capacity = sizemmmmm;
        }
    }
    int front()
    {
        return array[0];
    }
    int back()
    {
        return array[sizemmmmm];
    }
};

int main()
{
    vectorm myvector;
    cout << "Vector is Empty: " << myvector.is_empty() << endl;
    myvector.push_back(1);
    myvector.push_back(2);
    myvector.push_back(3);
    myvector.push_back(4);
    myvector.push_back(5);
    myvector.display();
    cout << "Size of my vector is :" << myvector.size() << endl;
    cout << "Capacity of my vector is :" << myvector.capacityy() << endl;
    myvector.erase(0);
    myvector.erase(1);
    myvector.display();
    cout << "Size of my vector is :" << myvector.size() << endl;
    cout << "Capacity of my vector is :" << myvector.capacityy() << endl;
    myvector.shrink();
    cout << "Size of my vector is :" << myvector.size() << endl;
    cout << "Capacity of my vector is :" << myvector.capacityy() << endl;
    return 0;
}
