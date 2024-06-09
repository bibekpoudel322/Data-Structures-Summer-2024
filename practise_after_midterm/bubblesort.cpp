#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
void bubblesort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void display(int array[], int size)
{
    cout << "Contents of the array is : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

int main()
{
    int myarray[] = {3, 6, 5, 9, 1, 33, 23, 34};
    display(myarray, 8);
    bubblesort(myarray, 8);
    cout << "After sorting : " << endl;
    display(myarray, 8);
    return 0;
}