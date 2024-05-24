#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
#include <fstream>
using namespace std;

int main()
{
    ofstream myfile("Newfile.txt");
    if (!myfile.is_open())
    {
        cout << "File failed to open." << endl;
        return 0;
    }
    myfile << "Hello everyone" << endl;

    return 0;
}