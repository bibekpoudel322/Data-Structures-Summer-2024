#include <iostream>
#include <list>
#include <fstream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;

int main()
{
    int n = 7;
    int array[] = {5, 3, 8, 2, 1, 9, 6};
    cout << "Unsorted array : \n";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    cout << "\n Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    return 0;
}