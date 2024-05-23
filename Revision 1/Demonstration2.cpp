#include <iostream>
#include <string>    // for string manipulation
#include <vector>    // for dynamic arrays
#include <algorithm> // for algorithms like sorting
#include <cmath>     // for mathematical functions
#include <iomanip>   // for formatting output
using namespace std;
class Person
{
private:
    string name;
    string idnum;

public:
    Person(string nm, string idnm) : name(nm), idnum(idnm) {}
    void printinfo()
    {
        cout << "Name : " << name << endl;
        cout << "Id number : " << idnum << endl;
    };
    string getName()
    {
        return name;
    }
};

class student : public Person
{
private:
    string major;

public:
    student(string nm, string idnm, string m) : Person(nm, idnm), major(m) {}
    void print()
    {
        printinfo();
        cout << "Major: " << major << endl;
    }
};
class faculty : public Person
{
private:
    string rank;

public:
    faculty(string n, string id, string r) : Person(n, id), rank(r) {}
    void print()
    {
        printinfo();
        cout << "Rank : " << rank << endl;
    }
};
int main()
{
    student s1("Bibek", "bp2376", "Computer engineering");
    faculty f2("KASSAB", "KSA3232", "Assistant Professor");
    f2.print();
    s1.print();
    return 0;
}