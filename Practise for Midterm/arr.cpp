#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
// sum of even integers using recursion upto n;
int recursion_sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n % 2 == 0)
    {
        return n + recursion_sum(n - 1);
    }
    else
    {
        return recursion_sum(n - 1);
    }
}
int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "The even sum is : " << recursion_sum(num) << endl;
    return 0;
}