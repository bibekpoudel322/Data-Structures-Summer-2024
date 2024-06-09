#include <iostream>
using namespace std;

int main()
{
    int i;

    // Example with ++i (pre-increment)
    cout << "Example with ++i (pre-increment):" << endl;
    for (i = 0; i < 5; ++i)
    {
        cout << "i = " << i << endl;
    }

    // Example with i++ (post-increment)
    cout << "\nExample with i++ (post-increment):" << endl;
    for (i = 0; i < 5; i++)
    {
        cout << "i = " << i << endl;
    }

    return 0;
}
