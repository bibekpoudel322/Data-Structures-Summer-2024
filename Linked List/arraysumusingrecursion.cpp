#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;

int sum(int array[], int n)
{
    if (n == 1)
        return array[0];
    else
        return array[n - 1] + sum(array, n - 1);
}
int main()
{
    int size = 5;
    int array[size] = {3, 2, 9, 4, 1};
    cout << "The sum of array is : " << sum(array, size);
    return 0;
}