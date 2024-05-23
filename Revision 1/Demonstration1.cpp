// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using namespace std;
int main()
{
    string s = "to be";
    string t = "not " + s;     // t = "not to be"
    string u = s + " or " + t; // u = "to be or not to be"
    std::cout << u;

    return 0;
}