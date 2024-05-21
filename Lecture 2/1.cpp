#include <iostream>
#include <string>
using namespace std;
class Person
{
private:
    std::string name;
    string city;
    int age;

public:
    Person(const std::string &n, int a, string c) : name(n), age(a), city(c) {}

    void printDetails()
    {
        std::cout << "This is  " << name << " " << age << " years old, " << "from " << city << std::endl;
    }
    bool isAdult()
    {
        return age >= 18;
    }
};

int main()
{
    // Create an instance of the Person class
    Person person1("Alice", 25, "Bharatpur");
    Person person2("Bibek", 10, "Orlando");

    // Print person's details using the member function
    person1.printDetails();
    cout << person1.isAdult() << endl;
    person2.printDetails();
    cout << person2.isAdult() << endl;

    return 0;
}
