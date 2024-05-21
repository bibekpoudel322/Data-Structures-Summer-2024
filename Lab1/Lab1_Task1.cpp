// Write a program that asks the user to enter apositiveinteger number N. The program shoulddisplayprimenumbersthat are smaller thanN.
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