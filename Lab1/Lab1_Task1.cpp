// Write a program that asks the user to enter apositiveinteger number N. The program shoulddisplayprimenumbersthat are smaller thanN.
//============================================================================
// Name         : lab1_2
// Author       : Bibek Poudel
// Version      :
// Date Created :5/23/2024
// Date Modified:
// Description  : Find the minimum and the maximum values in an Array using a
//				  function (findMinMax) that takes the array, its size and
//				  two variables min and max by reference.
//============================================================================
#include <iostream>
using namespace std;

// Function to check for Prime or not
bool isPrime(int num)
{
    if (num <= 1)
        return false;
    for (int i = 2; i < num; i++)
        if (num % i == 0)
            return false;
    return true;
}
int main()
{
    int N, i, count = 0;

    cout << "Enter a positive integer: ";
    cin >> N;

    cout << "Prime numbers smaller than " << N << " are: ";

    for (i = 2; i < N; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
            count++;
        }
    }
    cout << "\nTotal prime numbers found: " << count;

    return 0;
}