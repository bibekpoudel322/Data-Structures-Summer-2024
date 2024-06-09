#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
#include <list>

int main()
{
    // Create an empty list of integers
    list<int> myList;
    for (int i = 0; i < 10; i++)
    {
        myList.push_back(i);
    }
    for (list<int>::iterator i = myList.end(); i != myList.begin(); i--)
    {
        cout << *i << " ";
    }
    cout << "\n After removal of the even numbers:" << endl;
    for (list<int>::iterator i = myList.begin(); i != myList.end(); i++)
    {
        if (*i % 2 == 0)
        {
            i = myList.erase(i);
        }
    }
    for (list<int>::iterator i = myList.begin(); i != myList.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}