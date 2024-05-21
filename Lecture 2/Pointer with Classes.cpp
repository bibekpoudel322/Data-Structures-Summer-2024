#include <iostream>
#include <string>
using namespace std;
// Parent class
class Employee
{
public:
    int getSalary() { return salary; }

protected:
    // Protected members are public to classes derived from Employee and private to all other classes
    int salary;
};

// The class "Programmer" is a child class that inherits the members of "Employee"
class Programmer : public Employee
{
public:
    std::string programming_language;

    void setSalary(int s) { salary = s; }
};

int main()
{
    Programmer p;
    p.setSalary(5000);
    p.programming_language = "C++";

    std::cout << "Salary: " << p.getSalary() << std::endl;
    std::cout << "Programming Language: " << p.programming_language << std::endl;

    return 0;
}
