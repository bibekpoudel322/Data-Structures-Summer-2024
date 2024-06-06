// Factorial using recursion;
#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}
int sum_of_al(int array[], int lastIndex)
{
    if (lastIndex == 0)
    {
        return array[0];
    }
    else
    {
        return array[lastIndex] + sum_of_al(array, lastIndex - 1);
    }
}
int main()
{
    // Test case 4: Array with all positive numbers
    int arr4[] = {1, 2, 3, 4};
    cout << "Sum of array {1, 2, 3, 4}: " << sum_of_al(arr4, 3) << endl;
    return 0;
}